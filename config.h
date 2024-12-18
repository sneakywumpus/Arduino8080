//
// Intel 8080 CPU emulation on an Arduino Nano
//            derived from Z80PACK
// Copyright 2024, Udo Munk
//
// With this module the machine can be configured to run standalone
// software loaded from a file. Also allows to mount/unmount disk
// images with OS's and application software.
//
// History:
// 19-MAY-2024 implemented configuration dialog
// 21-MAY-2024 added mount/unmount of disk images
//

#define BS  0x08 // backspace
#define DEL 0x7f // delete

// read a config command line from the terminal
void get_cmdline(char *buf, int len)
{
  int i = 0;
  char c;

  for (;;) {
    while (!Serial.available())
      ;
    c = Serial.read();
    if ((c == BS) || (c == DEL)) {
      if (i >= 1) {
        Serial.write(BS);
        Serial.write(' ');
        Serial.write(BS);
        i--;
      }
    } else if (c != '\r') {
      if (i < len - 1) {
        buf[i++] = c;
        Serial.write(c);
        if (len == 2)
          break;
      }
    } else {
      break;
    }
  }
  buf[i] = '\0';
}

// prompt for a filename
static void prompt_fn(char *s)
{
  Serial.print(F("Filename: "));
  get_cmdline(s, 9);
  Serial.println();
}

// disk already mounted
static void mount_msg(void)
{
  Serial.println(F("Disk already mounted"));
}

// configuration dialog for the machine
void config(void)
{
  const char *cfg = "/CONF80/CFG.TXT";
  char s[10];
  int go_flag = 0;

  // try to read config file
  if (sd_file.openExistingSFN(cfg)) {
    sd_file.read(&fp_value, 1);
    sd_file.read(&disks[0], 22);
    sd_file.read(&disks[1], 22);
    sd_file.close();
  }

  while (!go_flag) {
    Serial.print(F("p - port 255: 0x"));
    Serial.println(fp_value, HEX);
    Serial.println(F("l - load file"));
    Serial.print(F("0 - Disk 0: "));
    Serial.println(disks[0]);
    Serial.print(F("1 - Disk 1: "));
    Serial.println(disks[1]);
    Serial.println(F("g - run machine\n"));
    Serial.print(F("Command: "));

    get_cmdline(s, 2);
    Serial.println(F("\n"));

    switch (*s) {
    case 'p':
again:
      Serial.print(F("Value: "));
      get_cmdline(s, 3);
      Serial.println(F("\n"));
      if ((*s >= 'a') && (*s <= 'f'))
        *s = toupper(*s);
      if ((*(s + 1) >= 'a') && (*(s + 1) <= 'f'))
        *(s + 1) = toupper(*(s + 1));
      if (!isxdigit(*s) || !isxdigit(*(s + 1))) {
        Serial.println(F("What?"));
        goto again;
      }
      fp_value = (*s <= '9') ? (*s - '0') : (*s - 'A' + 10);
      fp_value <<= 4;
      fp_value += (*(s + 1) <= '9') ? (*(s + 1) - '0') :
                  (*(s + 1) - 'A' + 10);
      break;

    case 'l':
      prompt_fn(s);
      load_file(s);
      break;

    case '0':
      prompt_fn(s);
      if (strlen(s) == 0) {
        disks[0][0] = 0x0;
        Serial.println();
      } else {
        mount_disk(0, s);
        if (!strcmp(disks[0], disks[1])) {
          mount_msg();
          disks[0][0] = 0x0;
          Serial.println();
        }
      }
      break;

    case '1':
      prompt_fn(s);
      if (strlen(s) == 0) {
        disks[1][0] = 0x0;
        Serial.println();
      } else {
        mount_disk(1, s);
        if (!strcmp(disks[0], disks[1])) {
          mount_msg();
          disks[1][0] = 0x0;
          Serial.println();
        }
      }
      break;

    case 'g':
      go_flag = 1;
      break;

    default:
      break;
    }
  }

  // try to save config file
  if (sd_file.openExistingSFN(cfg)) {
    sd_file.write(&fp_value, 1);
    sd_file.write(&disks[0], 22);
    sd_file.write(&disks[1], 22);
    sd_file.close();
  }
}
