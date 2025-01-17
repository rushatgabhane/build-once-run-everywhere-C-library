/* clang-format off */
/* charsets.c -- character set information and mappings

  (c) 1998-2006 (W3C) MIT, ERCIM, Keio University
  See tidy.h for the copyright notice.

*/

#include "third_party/tidy/forward.h"
#include "third_party/tidy/tidy.h"
#include "third_party/tidy/tmbstr.h"
#include "third_party/tidy/charsets.h"

/* todo: documentation of table and data       */
/* todo: integration of data and routines      */
/* todo: minor cleanup for ambiguous relations */
static struct _charsetInfo
{
    uint id;
    ctmbstr charset;
    uint codepage;
    uint stateful;
} const charsetInfo[] =
{
  {   1, "adobe-standard-encoding",                           0,  no }, /* IANA */
  {   1, "csadobestandardencoding",                           0,  no }, /* IANA */
  {   2, "adobe-symbol-encoding",                             0,  no }, /* IANA */
  {   2, "cshppsmath",                                        0,  no }, /* IANA */
  {   3, "iso-ir-99",                                         0,  no }, /* IANA */
  {   3, "ansi_x3.110-1983",                                  0,  no }, /* IANA */
  {   3, "csa_t500-1983",                                     0,  no }, /* IANA */
  {   3, "naplps",                                            0,  no }, /* IANA */
  {   3, "csiso99naplps",                                     0,  no }, /* IANA */
  {   4, "us-ascii",                                      20127,  no }, /* IANA */
  {   4, "iso-ir-6",                                      20127,  no }, /* IANA */
  {   4, "ansi_x3.4-1968",                                20127,  no }, /* IANA */
  {   4, "ansi_x3.4-1986",                                20127,  no }, /* IANA */
  {   4, "iso_646.irv:1991",                              20127,  no }, /* IANA */
  {   4, "ascii",                                         20127,  no }, /* IANA */
  {   4, "iso646-us",                                     20127,  no }, /* IANA */
  {   4, "us",                                            20127,  no }, /* IANA */
  {   4, "ibm367",                                        20127,  no }, /* IANA */
  {   4, "cp367",                                         20127,  no }, /* IANA */
  {   4, "csascii",                                       20127,  no }, /* IANA */
  {   4, "iso-ir-6us",                                    20127,  no }, /* MICROSOFT */
  {   5, "iso-ir-89",                                         0,  no }, /* IANA */
  {   5, "asmo_449",                                          0,  no }, /* IANA */
  {   5, "iso_9036",                                          0,  no }, /* IANA */
  {   5, "arabic7",                                           0,  no }, /* IANA */
  {   5, "csiso89asmo449",                                    0,  no }, /* IANA */
  {   6, "big5",                                            950,  no }, /* IANA */
  {   6, "csbig5",                                          950,  no }, /* IANA */
  {   6, "cn-big5",                                         950,  no }, /* MICROSOFT */
  {   6, "x-x-big5",                                        950,  no }, /* MICROSOFT */
  {   7, "big5-hkscs",                                      950,  no }, /* IANA */
  {   7, "cn-big5",                                         950,  no }, /* MICROSOFT */
  {   7, "x-x-big5",                                        950,  no }, /* MICROSOFT */
  {   8, "bocu-1",                                            0,  no }, /* IANA */
  {   8, "csbocu-1",                                          0,  no }, /* IANA */
  {   9, "iso-ir-4",                                          0,  no }, /* IANA */
  {   9, "bs_4730",                                           0,  no }, /* IANA */
  {   9, "iso646-gb",                                         0,  no }, /* IANA */
  {   9, "gb",                                                0,  no }, /* IANA */
  {   9, "uk",                                                0,  no }, /* IANA */
  {   9, "csiso4unitedkingdom",                               0,  no }, /* IANA */
  {  10, "iso-ir-47",                                         0,  no }, /* IANA */
  {  10, "bs_viewdata",                                       0,  no }, /* IANA */
  {  10, "csiso47bsviewdata",                                 0,  no }, /* IANA */
  {  11, "cesu-8",                                            0,  no }, /* IANA */
  {  11, "cscesu-8",                                          0,  no }, /* IANA */
  {  12, "iso-ir-121",                                        0,  no }, /* IANA */
  {  12, "csa_z243.4-1985-1",                                 0,  no }, /* IANA */
  {  12, "iso646-ca",                                         0,  no }, /* IANA */
  {  12, "csa7-1",                                            0,  no }, /* IANA */
  {  12, "ca",                                                0,  no }, /* IANA */
  {  12, "csiso121canadian1",                                 0,  no }, /* IANA */
  {  13, "iso-ir-122",                                        0,  no }, /* IANA */
  {  13, "csa_z243.4-1985-2",                                 0,  no }, /* IANA */
  {  13, "iso646-ca2",                                        0,  no }, /* IANA */
  {  13, "csa7-2",                                            0,  no }, /* IANA */
  {  13, "csiso122canadian2",                                 0,  no }, /* IANA */
  {  14, "iso-ir-123",                                        0,  no }, /* IANA */
  {  14, "csa_z243.4-1985-gr",                                0,  no }, /* IANA */
  {  14, "csiso123csaz24341985gr",                            0,  no }, /* IANA */
  {  15, "iso-ir-139",                                        0,  no }, /* IANA */
  {  15, "csn_369103",                                        0,  no }, /* IANA */
  {  15, "csiso139csn369103",                                 0,  no }, /* IANA */
  {  16, "dec-mcs",                                           0,  no }, /* IANA */
  {  16, "dec",                                               0,  no }, /* IANA */
  {  16, "csdecmcs",                                          0,  no }, /* IANA */
  {  17, "iso-ir-21",                                     20106,  no }, /* IANA */
  {  17, "din_66003",                                     20106,  no }, /* IANA */
  {  17, "de",                                            20106,  no }, /* IANA */
  {  17, "iso646-de",                                     20106,  no }, /* IANA */
  {  17, "csiso21german",                                 20106,  no }, /* IANA */
  {  17, "x-ia5-german",                                  20106,  no }, /* MICROSOFT */
  {  18, "dk-us",                                             0,  no }, /* IANA */
  {  18, "csdkus",                                            0,  no }, /* IANA */
  {  19, "ds_2089",                                           0,  no }, /* IANA */
  {  19, "ds2089",                                            0,  no }, /* IANA */
  {  19, "iso646-dk",                                         0,  no }, /* IANA */
  {  19, "dk",                                                0,  no }, /* IANA */
  {  19, "csiso646danish",                                    0,  no }, /* IANA */
  {  20, "ebcdic-at-de",                                      0,  no }, /* IANA */
  {  20, "csibmebcdicatde",                                   0,  no }, /* IANA */
  {  21, "ebcdic-at-de-a",                                    0,  no }, /* IANA */
  {  21, "csebcdicatdea",                                     0,  no }, /* IANA */
  {  22, "ebcdic-ca-fr",                                      0,  no }, /* IANA */
  {  22, "csebcdiccafr",                                      0,  no }, /* IANA */
  {  23, "ebcdic-dk-no",                                      0,  no }, /* IANA */
  {  23, "csebcdicdkno",                                      0,  no }, /* IANA */
  {  24, "ebcdic-dk-no-a",                                    0,  no }, /* IANA */
  {  24, "csebcdicdknoa",                                     0,  no }, /* IANA */
  {  25, "ebcdic-es",                                         0,  no }, /* IANA */
  {  25, "csebcdices",                                        0,  no }, /* IANA */
  {  26, "ebcdic-es-a",                                       0,  no }, /* IANA */
  {  26, "csebcdicesa",                                       0,  no }, /* IANA */
  {  27, "ebcdic-es-s",                                       0,  no }, /* IANA */
  {  27, "csebcdicess",                                       0,  no }, /* IANA */
  {  28, "ebcdic-fi-se",                                      0,  no }, /* IANA */
  {  28, "csebcdicfise",                                      0,  no }, /* IANA */
  {  29, "ebcdic-fi-se-a",                                    0,  no }, /* IANA */
  {  29, "csebcdicfisea",                                     0,  no }, /* IANA */
  {  30, "ebcdic-fr",                                         0,  no }, /* IANA */
  {  30, "csebcdicfr",                                        0,  no }, /* IANA */
  {  31, "ebcdic-it",                                         0,  no }, /* IANA */
  {  31, "csebcdicit",                                        0,  no }, /* IANA */
  {  32, "ebcdic-pt",                                         0,  no }, /* IANA */
  {  32, "csebcdicpt",                                        0,  no }, /* IANA */
  {  33, "ebcdic-uk",                                         0,  no }, /* IANA */
  {  33, "csebcdicuk",                                        0,  no }, /* IANA */
  {  34, "ebcdic-us",                                         0,  no }, /* IANA */
  {  34, "csebcdicus",                                        0,  no }, /* IANA */
  {  35, "iso-ir-111",                                        0,  no }, /* IANA */
  {  35, "ecma-cyrillic",                                     0,  no }, /* IANA */
  {  35, "csiso111ecmacyrillic",                              0,  no }, /* IANA */
  {  36, "iso-ir-17",                                         0,  no }, /* IANA */
  {  36, "es",                                                0,  no }, /* IANA */
  {  36, "iso646-es",                                         0,  no }, /* IANA */
  {  36, "csiso17spanish",                                    0,  no }, /* IANA */
  {  37, "iso-ir-85",                                         0,  no }, /* IANA */
  {  37, "es2",                                               0,  no }, /* IANA */
  {  37, "iso646-es2",                                        0,  no }, /* IANA */
  {  37, "csiso85spanish2",                                   0,  no }, /* IANA */
  {  38, "euc-kr",                                        51949,  no }, /* IANA */
  {  38, "cseuckr",                                       51949,  no }, /* IANA */
  {  39, "extended_unix_code_fixed_width_for_japanese",       0,  no }, /* IANA */
  {  39, "cseucfixwidjapanese",                               0,  no }, /* IANA */
  {  40, "euc-jp",                                        51932,  no }, /* IANA */
  {  40, "extended_unix_code_packed_format_for_japanese", 51932,  no }, /* IANA */
  {  40, "cseucpkdfmtjapanese",                           51932,  no }, /* IANA */
  {  40, "x-euc-jp",                                      51932,  no }, /* MICROSOFT */
  {  40, "x-euc",                                         51932,  no }, /* MICROSOFT */
  {  41, "gb18030",                                       54936,  no }, /* IANA */
  {  42, "gb2312",                                          936,  no }, /* IANA */
  {  42, "csgb2312",                                        936,  no }, /* IANA */
  {  42, "csgb231280",                                      936,  no }, /* MICROSOFT */
  {  42, "gb2312-80",                                       936,  no }, /* MICROSOFT */
  {  42, "gb231280",                                        936,  no }, /* MICROSOFT */
  {  42, "cn-gb",                                           936,  no }, /* MICROSOFT */
  {  43, "iso-ir-57",                                         0,  no }, /* IANA */
  {  43, "gb_1988-80",                                        0,  no }, /* IANA */
  {  43, "cn",                                                0,  no }, /* IANA */
  {  43, "iso646-cn",                                         0,  no }, /* IANA */
  {  43, "csiso57gb1988",                                     0,  no }, /* IANA */
  {  44, "iso-ir-58",                                       936,  no }, /* IANA */
  {  44, "gb_2312-80",                                      936,  no }, /* IANA */
  {  44, "chinese",                                         936,  no }, /* IANA */
  {  44, "csiso58gb231280",                                 936,  no }, /* IANA */
  {  44, "csgb231280",                                      936,  no }, /* MICROSOFT */
  {  44, "gb2312-80",                                       936,  no }, /* MICROSOFT */
  {  44, "gb231280",                                        936,  no }, /* MICROSOFT */
  {  44, "cn-gb",                                           936,  no }, /* MICROSOFT */
  {  45, "gbk",                                             936,  no }, /* IANA */
  {  45, "cp936",                                           936,  no }, /* IANA */
  {  45, "ms936",                                           936,  no }, /* IANA */
  {  45, "windows-936",                                     936,  no }, /* IANA */
  {  45, "csgb231280",                                      936,  no }, /* MICROSOFT */
  {  45, "gb2312-80",                                       936,  no }, /* MICROSOFT */
  {  45, "gb231280",                                        936,  no }, /* MICROSOFT */
  {  45, "cn-gb",                                           936,  no }, /* MICROSOFT */
  {  46, "iso-ir-153",                                        0,  no }, /* IANA */
  {  46, "gost_19768-74",                                     0,  no }, /* IANA */
  {  46, "st_sev_358-88",                                     0,  no }, /* IANA */
  {  46, "csiso153gost1976874",                               0,  no }, /* IANA */
  {  47, "iso-ir-150",                                        0,  no }, /* IANA */
  {  47, "greek-ccitt",                                       0,  no }, /* IANA */
  {  47, "csiso150",                                          0,  no }, /* IANA */
  {  47, "csiso150greekccitt",                                0,  no }, /* IANA */
  {  48, "iso-ir-88",                                         0,  no }, /* IANA */
  {  48, "greek7",                                            0,  no }, /* IANA */
  {  48, "csiso88greek7",                                     0,  no }, /* IANA */
  {  49, "iso-ir-18",                                         0,  no }, /* IANA */
  {  49, "greek7-old",                                        0,  no }, /* IANA */
  {  49, "csiso18greek7old",                                  0,  no }, /* IANA */
  {  50, "hp-desktop",                                        0,  no }, /* IANA */
  {  50, "cshpdesktop",                                       0,  no }, /* IANA */
  {  51, "hp-legal",                                          0,  no }, /* IANA */
  {  51, "cshplegal",                                         0,  no }, /* IANA */
  {  52, "hp-math8",                                          0,  no }, /* IANA */
  {  52, "cshpmath8",                                         0,  no }, /* IANA */
  {  53, "hp-pi-font",                                        0,  no }, /* IANA */
  {  53, "cshppifont",                                        0,  no }, /* IANA */
  {  54, "hp-roman8",                                         0,  no }, /* IANA */
  {  54, "roman8",                                            0,  no }, /* IANA */
  {  54, "r8",                                                0,  no }, /* IANA */
  {  54, "cshproman8",                                        0,  no }, /* IANA */
  {  55, "hz-gb-2312",                                    52936, yes }, /* IANA */
  {  56, "ibm-symbols",                                       0,  no }, /* IANA */
  {  56, "csibmsymbols",                                      0,  no }, /* IANA */
  {  57, "ibm-thai",                                      20838,  no }, /* IANA */
  {  57, "csibmthai",                                     20838,  no }, /* IANA */
  {  57, "x-ebcdic-thai",                                 20838,  no }, /* MICROSOFT */
  {  58, "ibm00858",                                        858,  no }, /* IANA */
  {  58, "ccsid00858",                                      858,  no }, /* IANA */
  {  58, "cp00858",                                         858,  no }, /* IANA */
  {  58, "pc-multilingual-850+euro",                        858,  no }, /* IANA */
  {  59, "ibm00924",                                      20924,  no }, /* IANA */
  {  59, "ccsid00924",                                    20924,  no }, /* IANA */
  {  59, "cp00924",                                       20924,  no }, /* IANA */
  {  59, "ebcdic-latin9--euro",                           20924,  no }, /* IANA */
  {  60, "ibm01140",                                       1140,  no }, /* IANA */
  {  60, "ccsid01140",                                     1140,  no }, /* IANA */
  {  60, "cp01140",                                        1140,  no }, /* IANA */
  {  60, "ebcdic-us-37+euro",                              1140,  no }, /* IANA */
  {  60, "x-ebcdic-cp-us-euro",                            1140,  no }, /* MICROSOFT */
  {  61, "ibm01141",                                       1141,  no }, /* IANA */
  {  61, "ccsid01141",                                     1141,  no }, /* IANA */
  {  61, "cp01141",                                        1141,  no }, /* IANA */
  {  61, "ebcdic-de-273+euro",                             1141,  no }, /* IANA */
  {  61, "x-ebcdic-germany-euro",                          1141,  no }, /* MICROSOFT */
  {  62, "ibm01142",                                       1142,  no }, /* IANA */
  {  62, "ccsid01142",                                     1142,  no }, /* IANA */
  {  62, "cp01142",                                        1142,  no }, /* IANA */
  {  62, "ebcdic-dk-277+euro",                             1142,  no }, /* IANA */
  {  62, "ebcdic-no-277+euro",                             1142,  no }, /* IANA */
  {  62, "x-ebcdic-denmarknorway-euro",                    1142,  no }, /* MICROSOFT */
  {  63, "ibm01143",                                       1143,  no }, /* IANA */
  {  63, "ccsid01143",                                     1143,  no }, /* IANA */
  {  63, "cp01143",                                        1143,  no }, /* IANA */
  {  63, "ebcdic-fi-278+euro",                             1143,  no }, /* IANA */
  {  63, "ebcdic-se-278+euro",                             1143,  no }, /* IANA */
  {  63, "x-ebcdic-france",                                1143,  no }, /* MICROSOFT */
  {  63, "x-ebcdic-finlandsweden-euro",                    1143,  no }, /* MICROSOFT */
  {  64, "ibm01144",                                       1144,  no }, /* IANA */
  {  64, "ccsid01144",                                     1144,  no }, /* IANA */
  {  64, "cp01144",                                        1144,  no }, /* IANA */
  {  64, "ebcdic-it-280+euro",                             1144,  no }, /* IANA */
  {  64, "x-ebcdic-italy-euro",                            1144,  no }, /* MICROSOFT */
  {  65, "ibm01145",                                       1145,  no }, /* IANA */
  {  65, "ccsid01145",                                     1145,  no }, /* IANA */
  {  65, "cp01145",                                        1145,  no }, /* IANA */
  {  65, "ebcdic-es-284+euro",                             1145,  no }, /* IANA */
  {  65, "x-ebcdic-spain-euro",                            1145,  no }, /* MICROSOFT */
  {  66, "ibm01146",                                       1146,  no }, /* IANA */
  {  66, "ccsid01146",                                     1146,  no }, /* IANA */
  {  66, "cp01146",                                        1146,  no }, /* IANA */
  {  66, "ebcdic-gb-285+euro",                             1146,  no }, /* IANA */
  {  66, "x-ebcdic-uk-euro",                               1146,  no }, /* MICROSOFT */
  {  67, "ibm01147",                                       1147,  no }, /* IANA */
  {  67, "ccsid01147",                                     1147,  no }, /* IANA */
  {  67, "cp01147",                                        1147,  no }, /* IANA */
  {  67, "ebcdic-fr-297+euro",                             1147,  no }, /* IANA */
  {  67, "x-ebcdic-france-euro",                           1147,  no }, /* MICROSOFT */
  {  68, "ibm01148",                                       1148,  no }, /* IANA */
  {  68, "ccsid01148",                                     1148,  no }, /* IANA */
  {  68, "cp01148",                                        1148,  no }, /* IANA */
  {  68, "ebcdic-international-500+euro",                  1148,  no }, /* IANA */
  {  68, "x-ebcdic-international-euro",                    1148,  no }, /* MICROSOFT */
  {  69, "ibm01149",                                       1149,  no }, /* IANA */
  {  69, "ccsid01149",                                     1149,  no }, /* IANA */
  {  69, "cp01149",                                        1149,  no }, /* IANA */
  {  69, "ebcdic-is-871+euro",                             1149,  no }, /* IANA */
  {  69, "x-ebcdic-icelandic-euro",                        1149,  no }, /* MICROSOFT */
  {  70, "ibm037",                                           37,  no }, /* IANA */
  {  70, "cp037",                                            37,  no }, /* IANA */
  {  70, "ebcdic-cp-us",                                     37,  no }, /* IANA */
  {  70, "ebcdic-cp-ca",                                     37,  no }, /* IANA */
  {  70, "ebcdic-cp-wt",                                     37,  no }, /* IANA */
  {  70, "ebcdic-cp-nl",                                     37,  no }, /* IANA */
  {  70, "csibm037",                                         37,  no }, /* IANA */
  {  71, "ibm038",                                            0,  no }, /* IANA */
  {  71, "ebcdic-int",                                        0,  no }, /* IANA */
  {  71, "cp038",                                             0,  no }, /* IANA */
  {  71, "csibm038",                                          0,  no }, /* IANA */
  {  72, "ibm1026",                                        1026,  no }, /* IANA */
  {  72, "cp1026",                                         1026,  no }, /* IANA */
  {  72, "csibm1026",                                      1026,  no }, /* IANA */
  {  73, "ibm1047",                                           0,  no }, /* IANA */
  {  73, "ibm-1047",                                          0,  no }, /* IANA */
  {  74, "ibm273",                                        20273,  no }, /* IANA */
  {  74, "cp273",                                         20273,  no }, /* IANA */
  {  74, "csibm273",                                      20273,  no }, /* IANA */
  {  74, "x-ebcdic-germany",                              20273,  no }, /* MICROSOFT */
  {  75, "ibm274",                                            0,  no }, /* IANA */
  {  75, "ebcdic-be",                                         0,  no }, /* IANA */
  {  75, "cp274",                                             0,  no }, /* IANA */
  {  75, "csibm274",                                          0,  no }, /* IANA */
  {  76, "ibm275",                                            0,  no }, /* IANA */
  {  76, "ebcdic-br",                                         0,  no }, /* IANA */
  {  76, "cp275",                                             0,  no }, /* IANA */
  {  76, "csibm275",                                          0,  no }, /* IANA */
  {  77, "ibm277",                                        20277,  no }, /* IANA */
  {  77, "ebcdic-cp-dk",                                  20277,  no }, /* IANA */
  {  77, "ebcdic-cp-no",                                  20277,  no }, /* IANA */
  {  77, "csibm277",                                      20277,  no }, /* IANA */
  {  77, "x-ebcdic-denmarknorway",                        20277,  no }, /* MICROSOFT */
  {  78, "ibm278",                                        20278,  no }, /* IANA */
  {  78, "cp278",                                         20278,  no }, /* IANA */
  {  78, "ebcdic-cp-fi",                                  20278,  no }, /* IANA */
  {  78, "ebcdic-cp-se",                                  20278,  no }, /* IANA */
  {  78, "csibm278",                                      20278,  no }, /* IANA */
  {  78, "x-ebcdic-finlandsweden",                        20278,  no }, /* MICROSOFT */
  {  79, "ibm280",                                        20280,  no }, /* IANA */
  {  79, "cp280",                                         20280,  no }, /* IANA */
  {  79, "ebcdic-cp-it",                                  20280,  no }, /* IANA */
  {  79, "csibm280",                                      20280,  no }, /* IANA */
  {  79, "x-ebcdic-italy",                                20280,  no }, /* MICROSOFT */
  {  80, "ibm281",                                            0,  no }, /* IANA */
  {  80, "ebcdic-jp-e",                                       0,  no }, /* IANA */
  {  80, "cp281",                                             0,  no }, /* IANA */
  {  80, "csibm281",                                          0,  no }, /* IANA */
  {  81, "ibm284",                                        20284,  no }, /* IANA */
  {  81, "cp284",                                         20284,  no }, /* IANA */
  {  81, "ebcdic-cp-es",                                  20284,  no }, /* IANA */
  {  81, "csibm284",                                      20284,  no }, /* IANA */
  {  81, "x-ebcdic-spain",                                20284,  no }, /* MICROSOFT */
  {  82, "ibm285",                                        20285,  no }, /* IANA */
  {  82, "cp285",                                         20285,  no }, /* IANA */
  {  82, "ebcdic-cp-gb",                                  20285,  no }, /* IANA */
  {  82, "csibm285",                                      20285,  no }, /* IANA */
  {  82, "x-ebcdic-uk",                                   20285,  no }, /* MICROSOFT */
  {  83, "ibm290",                                        20290,  no }, /* IANA */
  {  83, "cp290",                                         20290,  no }, /* IANA */
  {  83, "ebcdic-jp-kana",                                20290,  no }, /* IANA */
  {  83, "csibm290",                                      20290,  no }, /* IANA */
  {  83, "x-ebcdic-japanesekatakana",                     20290,  no }, /* MICROSOFT */
  {  84, "ibm297",                                        20297,  no }, /* IANA */
  {  84, "cp297",                                         20297,  no }, /* IANA */
  {  84, "ebcdic-cp-fr",                                  20297,  no }, /* IANA */
  {  84, "csibm297",                                      20297,  no }, /* IANA */
  {  85, "ibm420",                                        20420,  no }, /* IANA */
  {  85, "cp420",                                         20420,  no }, /* IANA */
  {  85, "ebcdic-cp-ar1",                                 20420,  no }, /* IANA */
  {  85, "csibm420",                                      20420,  no }, /* IANA */
  {  85, "x-ebcdic-arabic",                               20420,  no }, /* MICROSOFT */
  {  86, "ibm423",                                        20423,  no }, /* IANA */
  {  86, "cp423",                                         20423,  no }, /* IANA */
  {  86, "ebcdic-cp-gr",                                  20423,  no }, /* IANA */
  {  86, "csibm423",                                      20423,  no }, /* IANA */
  {  86, "x-ebcdic-greek",                                20423,  no }, /* MICROSOFT */
  {  87, "ibm424",                                        20424,  no }, /* IANA */
  {  87, "cp424",                                         20424,  no }, /* IANA */
  {  87, "ebcdic-cp-he",                                  20424,  no }, /* IANA */
  {  87, "csibm424",                                      20424,  no }, /* IANA */
  {  87, "x-ebcdic-hebrew",                               20424,  no }, /* MICROSOFT */
  {  88, "ibm437",                                          437,  no }, /* IANA */
  {  88, "cp437",                                           437,  no }, /* IANA */
  {  88, "437",                                             437,  no }, /* IANA */
  {  88, "cspc8codepage437",                                437,  no }, /* IANA */
  {  88, "codepage437",                                     437,  no }, /* MICROSOFT */
  {  88, "cspc8",                                           437,  no }, /* MICROSOFT */
  {  89, "ibm500",                                          500,  no }, /* IANA */
  {  89, "cp500",                                           500,  no }, /* IANA */
  {  89, "ebcdic-cp-be",                                    500,  no }, /* IANA */
  {  89, "ebcdic-cp-ch",                                    500,  no }, /* IANA */
  {  89, "csibm500",                                        500,  no }, /* IANA */
  {  90, "ibm775",                                          775,  no }, /* IANA */
  {  90, "cp775",                                           775,  no }, /* IANA */
  {  90, "cspc775baltic",                                   775,  no }, /* IANA */
  {  91, "ibm850",                                          850,  no }, /* IANA */
  {  91, "cp850",                                           850,  no }, /* IANA */
  {  91, "850",                                             850,  no }, /* IANA */
  {  91, "cspc850multilingual",                             850,  no }, /* IANA */
  {  92, "ibm851",                                            0,  no }, /* IANA */
  {  92, "cp851",                                             0,  no }, /* IANA */
  {  92, "851",                                               0,  no }, /* IANA */
  {  92, "csibm851",                                          0,  no }, /* IANA */
  {  93, "ibm852",                                          852,  no }, /* IANA */
  {  93, "cp852",                                           852,  no }, /* IANA */
  {  93, "852",                                             852,  no }, /* IANA */
  {  93, "cspcp852",                                        852,  no }, /* IANA */
  {  94, "ibm855",                                          855,  no }, /* IANA */
  {  94, "cp855",                                           855,  no }, /* IANA */
  {  94, "855",                                             855,  no }, /* IANA */
  {  94, "csibm855",                                        855,  no }, /* IANA */
  {  95, "ibm857",                                          857,  no }, /* IANA */
  {  95, "cp857",                                           857,  no }, /* IANA */
  {  95, "857",                                             857,  no }, /* IANA */
  {  95, "csibm857",                                        857,  no }, /* IANA */
  {  96, "ibm860",                                          860,  no }, /* IANA */
  {  96, "cp860",                                           860,  no }, /* IANA */
  {  96, "860",                                             860,  no }, /* IANA */
  {  96, "csibm860",                                        860,  no }, /* IANA */
  {  97, "ibm861",                                          861,  no }, /* IANA */
  {  97, "cp861",                                           861,  no }, /* IANA */
  {  97, "861",                                             861,  no }, /* IANA */
  {  97, "cp-is",                                           861,  no }, /* IANA */
  {  97, "csibm861",                                        861,  no }, /* IANA */
  {  98, "ibm862",                                          862,  no }, /* IANA */
  {  98, "cp862",                                           862,  no }, /* IANA */
  {  98, "862",                                             862,  no }, /* IANA */
  {  98, "cspc862latinhebrew",                              862,  no }, /* IANA */
  {  98, "dos-862",                                         862,  no }, /* MICROSOFT */
  {  99, "ibm863",                                          863,  no }, /* IANA */
  {  99, "cp863",                                           863,  no }, /* IANA */
  {  99, "863",                                             863,  no }, /* IANA */
  {  99, "csibm863",                                        863,  no }, /* IANA */
  { 100, "ibm864",                                          864,  no }, /* IANA */
  { 100, "cp864",                                           864,  no }, /* IANA */
  { 100, "csibm864",                                        864,  no }, /* IANA */
  { 101, "ibm865",                                          865,  no }, /* IANA */
  { 101, "cp865",                                           865,  no }, /* IANA */
  { 101, "865",                                             865,  no }, /* IANA */
  { 101, "csibm865",                                        865,  no }, /* IANA */
  { 102, "ibm866",                                          866,  no }, /* IANA */
  { 102, "cp866",                                           866,  no }, /* IANA */
  { 102, "866",                                             866,  no }, /* IANA */
  { 102, "csibm866",                                        866,  no }, /* IANA */
  { 103, "ibm868",                                            0,  no }, /* IANA */
  { 103, "cp868",                                             0,  no }, /* IANA */
  { 103, "cp-ar",                                             0,  no }, /* IANA */
  { 103, "csibm868",                                          0,  no }, /* IANA */
  { 104, "ibm869",                                          869,  no }, /* IANA */
  { 104, "cp869",                                           869,  no }, /* IANA */
  { 104, "869",                                             869,  no }, /* IANA */
  { 104, "cp-gr",                                           869,  no }, /* IANA */
  { 104, "csibm869",                                        869,  no }, /* IANA */
  { 105, "ibm870",                                          870,  no }, /* IANA */
  { 105, "cp870",                                           870,  no }, /* IANA */
  { 105, "ebcdic-cp-roece",                                 870,  no }, /* IANA */
  { 105, "ebcdic-cp-yu",                                    870,  no }, /* IANA */
  { 105, "csibm870",                                        870,  no }, /* IANA */
  { 106, "ibm871",                                        20871,  no }, /* IANA */
  { 106, "cp871",                                         20871,  no }, /* IANA */
  { 106, "ebcdic-cp-is",                                  20871,  no }, /* IANA */
  { 106, "csibm871",                                      20871,  no }, /* IANA */
  { 106, "x-ebcdic-icelandic",                            20871,  no }, /* MICROSOFT */
  { 107, "ibm880",                                        20880,  no }, /* IANA */
  { 107, "cp880",                                         20880,  no }, /* IANA */
  { 107, "ebcdic-cyrillic",                               20880,  no }, /* IANA */
  { 107, "csibm880",                                      20880,  no }, /* IANA */
  { 107, "x-ebcdic-cyrillicrussian",                      20880,  no }, /* MICROSOFT */
  { 108, "ibm891",                                            0,  no }, /* IANA */
  { 108, "cp891",                                             0,  no }, /* IANA */
  { 108, "csibm891",                                          0,  no }, /* IANA */
  { 109, "ibm903",                                            0,  no }, /* IANA */
  { 109, "cp903",                                             0,  no }, /* IANA */
  { 109, "csibm903",                                          0,  no }, /* IANA */
  { 110, "ibm904",                                            0,  no }, /* IANA */
  { 110, "cp904",                                             0,  no }, /* IANA */
  { 110, "904",                                               0,  no }, /* IANA */
  { 110, "csibbm904",                                         0,  no }, /* IANA */
  { 111, "ibm905",                                        20905,  no }, /* IANA */
  { 111, "cp905",                                         20905,  no }, /* IANA */
  { 111, "ebcdic-cp-tr",                                  20905,  no }, /* IANA */
  { 111, "csibm905",                                      20905,  no }, /* IANA */
  { 111, "x-ebcdic-turkish",                              20905,  no }, /* MICROSOFT */
  { 112, "ibm918",                                            0,  no }, /* IANA */
  { 112, "cp918",                                             0,  no }, /* IANA */
  { 112, "ebcdic-cp-ar2",                                     0,  no }, /* IANA */
  { 112, "csibm918",                                          0,  no }, /* IANA */
  { 113, "iso-ir-143",                                        0,  no }, /* IANA */
  { 113, "iec_p27-1",                                         0,  no }, /* IANA */
  { 113, "csiso143iecp271",                                   0,  no }, /* IANA */
  { 114, "iso-ir-49",                                         0,  no }, /* IANA */
  { 114, "inis",                                              0,  no }, /* IANA */
  { 114, "csiso49inis",                                       0,  no }, /* IANA */
  { 115, "iso-ir-50",                                         0,  no }, /* IANA */
  { 115, "inis-8",                                            0,  no }, /* IANA */
  { 115, "csiso50inis8",                                      0,  no }, /* IANA */
  { 116, "iso-ir-51",                                         0,  no }, /* IANA */
  { 116, "inis-cyrillic",                                     0,  no }, /* IANA */
  { 116, "csiso51iniscyrillic",                               0,  no }, /* IANA */
  { 117, "invariant",                                         0,  no }, /* IANA */
  { 117, "csinvariant",                                       0,  no }, /* IANA */
  { 118, "iso-10646-j-1",                                     0,  no }, /* IANA */
  { 119, "iso-10646-ucs-2",                                1200,  no }, /* IANA */
  { 119, "csunicode",                                      1200,  no }, /* IANA */
  { 119, "unicode",                                        1200,  no }, /* MICROSOFT */
  { 120, "iso-10646-ucs-4",                                   0,  no }, /* IANA */
  { 120, "csucs4",                                            0,  no }, /* IANA */
  { 121, "iso-10646-ucs-basic",                               0,  no }, /* IANA */
  { 121, "csunicodeascii",                                    0,  no }, /* IANA */
  { 122, "iso-10646-unicode-latin1",                          0,  no }, /* IANA */
  { 122, "iso-10646",                                         0,  no }, /* IANA */
  { 122, "csunicodelatin1",                                   0,  no }, /* IANA */
  { 123, "iso-10646-utf-1",                                   0,  no }, /* IANA */
  { 123, "csiso10646utf1",                                    0,  no }, /* IANA */
  { 124, "iso-2022-cn",                                       0, yes }, /* IANA */
  { 125, "iso-2022-cn-ext",                                   0, yes }, /* IANA */
  { 126, "iso-2022-jp",                                   50220, yes }, /* IANA */
  { 126, "csiso2022jp",                                   50220, yes }, /* IANA */
  { 127, "iso-2022-jp-2",                                     0, yes }, /* IANA */
  { 127, "csiso2022jp2",                                      0, yes }, /* IANA */
  { 128, "iso-2022-kr",                                   50225, yes }, /* IANA */
  { 128, "csiso2022kr",                                   50225, yes }, /* IANA */
  { 129, "iso-8859-1-windows-3.0-latin-1",                    0,  no }, /* IANA */
  { 129, "cswindows30latin1",                                 0,  no }, /* IANA */
  { 130, "iso-8859-1-windows-3.1-latin-1",                    0,  no }, /* IANA */
  { 130, "cswindows31latin1",                                 0,  no }, /* IANA */
  { 131, "iso-8859-10",                                       0,  no }, /* IANA */
  { 131, "iso-ir-157",                                        0,  no }, /* IANA */
  { 131, "l6",                                                0,  no }, /* IANA */
  { 131, "iso_8859-10:1992",                                  0,  no }, /* IANA */
  { 131, "csisolatin6",                                       0,  no }, /* IANA */
  { 131, "latin6",                                            0,  no }, /* IANA */
  { 132, "iso-8859-13",                                   28603,  no }, /* IANA */
  { 133, "iso-8859-14",                                       0,  no }, /* IANA */
  { 133, "iso-ir-199",                                        0,  no }, /* IANA */
  { 133, "iso-celtic",                                        0,  no }, /* IANA */
  { 133, "iso_8859-14:1998",                                  0,  no }, /* IANA */
  { 133, "iso_8859-14",                                       0,  no }, /* IANA */
  { 133, "latin8",                                            0,  no }, /* IANA */
  { 133, "l8",                                                0,  no }, /* IANA */
  { 134, "iso-8859-15",                                   28605,  no }, /* IANA */
  { 134, "iso_8859-15",                                   28605,  no }, /* IANA */
  { 134, "latin-9",                                       28605,  no }, /* IANA */
  { 134, "l9",                                            28605,  no }, /* MICROSOFT */
  { 134, "latin9",                                        28605,  no }, /* MICROSOFT */
  { 135, "iso-8859-16",                                       0,  no }, /* IANA */
  { 135, "iso-ir-226",                                        0,  no }, /* IANA */
  { 135, "iso_8859-16:2001",                                  0,  no }, /* IANA */
  { 135, "iso_8859-16",                                       0,  no }, /* IANA */
  { 135, "latin10",                                           0,  no }, /* IANA */
  { 135, "l10",                                               0,  no }, /* IANA */
  { 136, "iso-8859-2-windows-latin-2",                        0,  no }, /* IANA */
  { 136, "cswindows31latin2",                                 0,  no }, /* IANA */
  { 137, "iso-8859-9-windows-latin-5",                        0,  no }, /* IANA */
  { 137, "cswindows31latin5",                                 0,  no }, /* IANA */
  { 138, "iso-ir-90",                                         0,  no }, /* IANA */
  { 138, "csiso90",                                           0,  no }, /* IANA */
  { 139, "iso-unicode-ibm-1261",                              0,  no }, /* IANA */
  { 139, "csunicodeibm1261",                                  0,  no }, /* IANA */
  { 140, "iso-unicode-ibm-1264",                              0,  no }, /* IANA */
  { 140, "csunicodeibm1264",                                  0,  no }, /* IANA */
  { 141, "iso-unicode-ibm-1265",                              0,  no }, /* IANA */
  { 141, "csunicodeibm1265",                                  0,  no }, /* IANA */
  { 142, "iso-unicode-ibm-1268",                              0,  no }, /* IANA */
  { 142, "csunicodeibm1268",                                  0,  no }, /* IANA */
  { 143, "iso-unicode-ibm-1276",                              0,  no }, /* IANA */
  { 143, "csunicodeibm1276",                                  0,  no }, /* IANA */
  { 144, "iso-ir-155",                                        0,  no }, /* IANA */
  { 144, "iso_10367-box",                                     0,  no }, /* IANA */
  { 144, "csiso10367box",                                     0,  no }, /* IANA */
  { 145, "iso-ir-98",                                         0,  no }, /* IANA */
  { 145, "iso_2033-1983",                                     0,  no }, /* IANA */
  { 145, "e13b",                                              0,  no }, /* IANA */
  { 145, "csiso2033",                                         0,  no }, /* IANA */
  { 146, "iso-ir-37",                                         0,  no }, /* IANA */
  { 146, "iso_5427",                                          0,  no }, /* IANA */
  { 146, "csiso5427cyrillic",                                 0,  no }, /* IANA */
  { 147, "iso-ir-54",                                         0,  no }, /* IANA */
  { 147, "iso_5427:1981",                                     0,  no }, /* IANA */
  { 147, "iso5427cyrillic1981",                               0,  no }, /* IANA */
  { 148, "iso-ir-55",                                         0,  no }, /* IANA */
  { 148, "iso_5428:1980",                                     0,  no }, /* IANA */
  { 148, "csiso5428greek",                                    0,  no }, /* IANA */
  { 149, "iso_646.basic:1983",                                0,  no }, /* IANA */
  { 149, "ref",                                               0,  no }, /* IANA */
  { 149, "csiso646basic1983",                                 0,  no }, /* IANA */
  { 150, "iso-ir-2",                                      20105,  no }, /* IANA */
  { 150, "iso_646.irv:1983",                              20105,  no }, /* IANA */
  { 150, "irv",                                           20105,  no }, /* IANA */
  { 150, "csiso2intlrefversion",                          20105,  no }, /* IANA */
  { 150, "x-ia5",                                         20105,  no }, /* MICROSOFT */
  { 151, "iso-ir-152",                                        0,  no }, /* IANA */
  { 151, "iso_6937-2-25",                                     0,  no }, /* IANA */
  { 151, "csiso6937add",                                      0,  no }, /* IANA */
  { 152, "iso-ir-142",                                        0,  no }, /* IANA */
  { 152, "iso_6937-2-add",                                    0,  no }, /* IANA */
  { 152, "csisotextcomm",                                     0,  no }, /* IANA */
  { 153, "iso-8859-1",                                    28591,  no }, /* IANA */
  { 153, "iso-ir-100",                                    28591,  no }, /* IANA */
  { 153, "iso_8859-1:1987",                               28591,  no }, /* IANA */
  { 153, "iso_8859-1",                                    28591,  no }, /* IANA */
  { 153, "latin1",                                        28591,  no }, /* IANA */
  { 153, "l1",                                            28591,  no }, /* IANA */
  { 153, "ibm819",                                        28591,  no }, /* IANA */
  { 153, "cp819",                                         28591,  no }, /* IANA */
  { 153, "csisolatin1",                                   28591,  no }, /* IANA */
  { 153, "iso8859-1",                                     28591,  no }, /* MICROSOFT */
  { 154, "iso-8859-2",                                    28592,  no }, /* IANA */
  { 154, "iso-ir-101",                                    28592,  no }, /* IANA */
  { 154, "iso_8859-2:1987",                               28592,  no }, /* IANA */
  { 154, "iso_8859-2",                                    28592,  no }, /* IANA */
  { 154, "latin2",                                        28592,  no }, /* IANA */
  { 154, "l2",                                            28592,  no }, /* IANA */
  { 154, "csisolatin2",                                   28592,  no }, /* IANA */
  { 154, "iso8859-2",                                     28592,  no }, /* MICROSOFT */
  { 155, "iso-8859-3",                                    28593,  no }, /* IANA */
  { 155, "iso-ir-109",                                    28593,  no }, /* IANA */
  { 155, "iso_8859-3:1988",                               28593,  no }, /* IANA */
  { 155, "iso_8859-3",                                    28593,  no }, /* IANA */
  { 155, "latin3",                                        28593,  no }, /* IANA */
  { 155, "l3",                                            28593,  no }, /* IANA */
  { 155, "csisolatin3",                                   28593,  no }, /* IANA */
  { 156, "iso-8859-4",                                    28594,  no }, /* IANA */
  { 156, "iso-ir-110",                                    28594,  no }, /* IANA */
  { 156, "iso_8859-4:1988",                               28594,  no }, /* IANA */
  { 156, "iso_8859-4",                                    28594,  no }, /* IANA */
  { 156, "latin4",                                        28594,  no }, /* IANA */
  { 156, "l4",                                            28594,  no }, /* IANA */
  { 156, "csisolatin4",                                   28594,  no }, /* IANA */
  { 157, "iso-8859-5",                                    28595,  no }, /* IANA */
  { 157, "iso-ir-144",                                    28595,  no }, /* IANA */
  { 157, "iso_8859-5:1988",                               28595,  no }, /* IANA */
  { 157, "iso_8859-5",                                    28595,  no }, /* IANA */
  { 157, "cyrillic",                                      28595,  no }, /* IANA */
  { 157, "csisolatincyrillic",                            28595,  no }, /* IANA */
  { 158, "iso-8859-6-e",                                      0,  no }, /* IANA */
  { 158, "iso_8859-6-e",                                      0,  no }, /* IANA */
  { 158, "csiso88596e",                                       0,  no }, /* IANA */
  { 159, "iso-8859-6-i",                                      0,  no }, /* IANA */
  { 159, "iso_8859-6-i",                                      0,  no }, /* IANA */
  { 159, "csiso88596i",                                       0,  no }, /* IANA */
  { 160, "iso-8859-6",                                    28596,  no }, /* IANA */
  { 160, "iso-ir-127",                                    28596,  no }, /* IANA */
  { 160, "iso_8859-6:1987",                               28596,  no }, /* IANA */
  { 160, "iso_8859-6",                                    28596,  no }, /* IANA */
  { 160, "ecma-114",                                      28596,  no }, /* IANA */
  { 160, "asmo-708",                                      28596,  no }, /* IANA */
  { 160, "arabic",                                        28596,  no }, /* IANA */
  { 160, "csisolatinarabic",                              28596,  no }, /* IANA */
  { 161, "iso-8859-7",                                    28597,  no }, /* IANA */
  { 161, "iso-ir-126",                                    28597,  no }, /* IANA */
  { 161, "iso_8859-7:1987",                               28597,  no }, /* IANA */
  { 161, "iso_8859-7",                                    28597,  no }, /* IANA */
  { 161, "elot_928",                                      28597,  no }, /* IANA */
  { 161, "ecma-118",                                      28597,  no }, /* IANA */
  { 161, "greek",                                         28597,  no }, /* IANA */
  { 161, "greek8",                                        28597,  no }, /* IANA */
  { 161, "csisolatingreek",                               28597,  no }, /* IANA */
  { 162, "iso-8859-8-e",                                      0,  no }, /* IANA */
  { 162, "iso_8859-8-e",                                      0,  no }, /* IANA */
  { 162, "csiso88598e",                                       0,  no }, /* IANA */
  { 163, "iso-8859-8-i",                                  38598,  no }, /* IANA */
  { 163, "iso_8859-8-i",                                  38598,  no }, /* IANA */
  { 163, "csiso88598i",                                   38598,  no }, /* IANA */
  { 164, "iso-8859-8",                                    28598,  no }, /* IANA */
  { 164, "iso-ir-138",                                    28598,  no }, /* IANA */
  { 164, "iso_8859-8:1988",                               28598,  no }, /* IANA */
  { 164, "iso_8859-8",                                    28598,  no }, /* IANA */
  { 164, "hebrew",                                        28598,  no }, /* IANA */
  { 164, "csisolatinhebrew",                              28598,  no }, /* IANA */
  { 164, "logical",                                       28598,  no }, /* MICROSOFT */
  { 164, "visual",                                        28598,  no }, /* MICROSOFT */
  { 165, "iso-8859-9",                                    28599,  no }, /* IANA */
  { 165, "iso-ir-148",                                    28599,  no }, /* IANA */
  { 165, "iso_8859-9:1989",                               28599,  no }, /* IANA */
  { 165, "iso_8859-9",                                    28599,  no }, /* IANA */
  { 165, "latin5",                                        28599,  no }, /* IANA */
  { 165, "l5",                                            28599,  no }, /* IANA */
  { 165, "csisolatin5",                                   28599,  no }, /* IANA */
  { 166, "iso-ir-154",                                        0,  no }, /* IANA */
  { 166, "iso_8859-supp",                                     0,  no }, /* IANA */
  { 166, "latin1-2-5",                                        0,  no }, /* IANA */
  { 166, "csiso8859supp",                                     0,  no }, /* IANA */
  { 167, "iso-ir-15",                                         0,  no }, /* IANA */
  { 167, "it",                                                0,  no }, /* IANA */
  { 167, "iso646-it",                                         0,  no }, /* IANA */
  { 167, "csiso15italian",                                    0,  no }, /* IANA */
  { 168, "iso-ir-13",                                         0,  no }, /* IANA */
  { 168, "jis_c6220-1969-jp",                                 0,  no }, /* IANA */
  { 168, "jis_c6220-1969",                                    0,  no }, /* IANA */
  { 168, "katakana",                                          0,  no }, /* IANA */
  { 168, "x0201-7",                                           0,  no }, /* IANA */
  { 168, "csiso13jisc6220jp",                                 0,  no }, /* IANA */
  { 169, "iso-ir-14",                                         0,  no }, /* IANA */
  { 169, "jis_c6220-1969-ro",                                 0,  no }, /* IANA */
  { 169, "jp",                                                0,  no }, /* IANA */
  { 169, "iso646-jp",                                         0,  no }, /* IANA */
  { 169, "csiso14jisc6220ro",                                 0,  no }, /* IANA */
  { 170, "iso-ir-42",                                         0,  no }, /* IANA */
  { 170, "jis_c6226-1978",                                    0,  no }, /* IANA */
  { 170, "csiso42jisc62261978",                               0,  no }, /* IANA */
  { 171, "iso-ir-87",                                         0,  no }, /* IANA */
  { 171, "jis_c6226-1983",                                    0,  no }, /* IANA */
  { 171, "x0208",                                             0,  no }, /* IANA */
  { 171, "jis_x0208-1983",                                    0,  no }, /* IANA */
  { 171, "csiso87jisx0208",                                   0,  no }, /* IANA */
  { 172, "iso-ir-91",                                         0,  no }, /* IANA */
  { 172, "jis_c6229-1984-a",                                  0,  no }, /* IANA */
  { 172, "jp-ocr-a",                                          0,  no }, /* IANA */
  { 172, "csiso91jisc62291984a",                              0,  no }, /* IANA */
  { 173, "iso-ir-92",                                         0,  no }, /* IANA */
  { 173, "jis_c6229-1984-b",                                  0,  no }, /* IANA */
  { 173, "iso646-jp-ocr-b",                                   0,  no }, /* IANA */
  { 173, "jp-ocr-b",                                          0,  no }, /* IANA */
  { 173, "csiso92jisc62991984b",                              0,  no }, /* IANA */
  { 174, "iso-ir-93",                                         0,  no }, /* IANA */
  { 174, "jis_c6229-1984-b-add",                              0,  no }, /* IANA */
  { 174, "jp-ocr-b-add",                                      0,  no }, /* IANA */
  { 174, "csiso93jis62291984badd",                            0,  no }, /* IANA */
  { 175, "iso-ir-94",                                         0,  no }, /* IANA */
  { 175, "jis_c6229-1984-hand",                               0,  no }, /* IANA */
  { 175, "jp-ocr-hand",                                       0,  no }, /* IANA */
  { 175, "csiso94jis62291984hand",                            0,  no }, /* IANA */
  { 176, "iso-ir-95",                                         0,  no }, /* IANA */
  { 176, "jis_c6229-1984-hand-add",                           0,  no }, /* IANA */
  { 176, "jp-ocr-hand-add",                                   0,  no }, /* IANA */
  { 176, "csiso95jis62291984handadd",                         0,  no }, /* IANA */
  { 177, "iso-ir-96",                                         0,  no }, /* IANA */
  { 177, "jis_c6229-1984-kana",                               0,  no }, /* IANA */
  { 177, "csiso96jisc62291984kana",                           0,  no }, /* IANA */
  { 178, "jis_encoding",                                      0,  no }, /* IANA */
  { 178, "csjisencoding",                                     0,  no }, /* IANA */
  { 179, "jis_x0201",                                         0,  no }, /* IANA */
  { 179, "x0201",                                             0,  no }, /* IANA */
  { 179, "cshalfwidthkatakana",                               0,  no }, /* IANA */
  { 180, "iso-ir-159",                                        0,  no }, /* IANA */
  { 180, "jis_x0212-1990",                                    0,  no }, /* IANA */
  { 180, "x0212",                                             0,  no }, /* IANA */
  { 180, "csiso159jisx02121990",                              0,  no }, /* IANA */
  { 181, "iso-ir-141",                                        0,  no }, /* IANA */
  { 181, "jus_i.b1.002",                                      0,  no }, /* IANA */
  { 181, "iso646-yu",                                         0,  no }, /* IANA */
  { 181, "js",                                                0,  no }, /* IANA */
  { 181, "yu",                                                0,  no }, /* IANA */
  { 181, "csiso141jusib1002",                                 0,  no }, /* IANA */
  { 182, "iso-ir-147",                                        0,  no }, /* IANA */
  { 182, "jus_i.b1.003-mac",                                  0,  no }, /* IANA */
  { 182, "macedonian",                                        0,  no }, /* IANA */
  { 182, "csiso147macedonian",                                0,  no }, /* IANA */
  { 183, "iso-ir-146",                                        0,  no }, /* IANA */
  { 183, "jus_i.b1.003-serb",                                 0,  no }, /* IANA */
  { 183, "serbian",                                           0,  no }, /* IANA */
  { 183, "csiso146serbian",                                   0,  no }, /* IANA */
  { 184, "koi8-r",                                        20866,  no }, /* IANA */
  { 184, "cskoi8r",                                       20866,  no }, /* IANA */
  { 184, "koi8",                                          20866,  no }, /* MICROSOFT */
  { 184, "koi",                                           20866,  no }, /* MICROSOFT */
  { 184, "koi8r",                                         20866,  no }, /* MICROSOFT */
  { 185, "koi8-u",                                        21866,  no }, /* IANA */
  { 185, "koi8-ru",                                       21866,  no }, /* MICROSOFT */
  { 186, "iso-ir-149",                                      949,  no }, /* IANA */
  { 186, "ks_c_5601-1987",                                  949,  no }, /* IANA */
  { 186, "ks_c_5601-1989",                                  949,  no }, /* IANA */
  { 186, "ksc_5601",                                        949,  no }, /* IANA */
  { 186, "korean",                                          949,  no }, /* IANA */
  { 186, "csksc56011987",                                   949,  no }, /* IANA */
  { 186, "ks_c_5601_1987",                                  949,  no }, /* MICROSOFT */
  { 186, "ksc5601",                                         949,  no }, /* MICROSOFT */
  { 186, "ks_c_5601",                                       949,  no }, /* MICROSOFT */
  { 187, "ksc5636",                                           0,  no }, /* IANA */
  { 187, "iso646-kr",                                         0,  no }, /* IANA */
  { 187, "csksc5636",                                         0,  no }, /* IANA */
  { 188, "iso-ir-19",                                         0,  no }, /* IANA */
  { 188, "latin-greek",                                       0,  no }, /* IANA */
  { 188, "csiso19latingreek",                                 0,  no }, /* IANA */
  { 189, "iso-ir-27",                                         0,  no }, /* IANA */
  { 189, "latin-greek-1",                                     0,  no }, /* IANA */
  { 189, "csiso27latingreek1",                                0,  no }, /* IANA */
  { 190, "iso-ir-158",                                        0,  no }, /* IANA */
  { 190, "latin-lap",                                         0,  no }, /* IANA */
  { 190, "lap",                                               0,  no }, /* IANA */
  { 190, "csiso158lap",                                       0,  no }, /* IANA */
  { 191, "macintosh",                                     10000,  no }, /* IANA */
  { 191, "mac",                                           10000,  no }, /* IANA */
  { 191, "csmacintosh",                                   10000,  no }, /* IANA */
  { 192, "microsoft-publishing",                              0,  no }, /* IANA */
  { 192, "csmicrosoftpublishing",                             0,  no }, /* IANA */
  { 193, "mnem",                                              0,  no }, /* IANA */
  { 193, "csmnem",                                            0,  no }, /* IANA */
  { 194, "mnemonic",                                          0,  no }, /* IANA */
  { 194, "csmnemonic",                                        0,  no }, /* IANA */
  { 195, "iso-ir-86",                                         0,  no }, /* IANA */
  { 195, "msz_7795.3",                                        0,  no }, /* IANA */
  { 195, "iso646-hu",                                         0,  no }, /* IANA */
  { 195, "hu",                                                0,  no }, /* IANA */
  { 195, "csiso86hungarian",                                  0,  no }, /* IANA */
  { 196, "iso-ir-9-1",                                        0,  no }, /* IANA */
  { 196, "nats-dano",                                         0,  no }, /* IANA */
  { 196, "csnatsdano",                                        0,  no }, /* IANA */
  { 197, "iso-ir-9-2",                                        0,  no }, /* IANA */
  { 197, "nats-dano-add",                                     0,  no }, /* IANA */
  { 197, "csnatsdanoadd",                                     0,  no }, /* IANA */
  { 198, "iso-ir-8-1",                                        0,  no }, /* IANA */
  { 198, "nats-sefi",                                         0,  no }, /* IANA */
  { 198, "csnatssefi",                                        0,  no }, /* IANA */
  { 199, "iso-ir-8-2",                                        0,  no }, /* IANA */
  { 199, "nats-sefi-add",                                     0,  no }, /* IANA */
  { 199, "csnatssefiadd",                                     0,  no }, /* IANA */
  { 200, "iso-ir-151",                                        0,  no }, /* IANA */
  { 200, "nc_nc00-10:81",                                     0,  no }, /* IANA */
  { 200, "cuba",                                              0,  no }, /* IANA */
  { 200, "iso646-cu",                                         0,  no }, /* IANA */
  { 200, "csiso151cuba",                                      0,  no }, /* IANA */
  { 201, "iso-ir-69",                                         0,  no }, /* IANA */
  { 201, "nf_z_62-010",                                       0,  no }, /* IANA */
  { 201, "iso646-fr",                                         0,  no }, /* IANA */
  { 201, "fr",                                                0,  no }, /* IANA */
  { 201, "csiso69french",                                     0,  no }, /* IANA */
  { 202, "iso-ir-25",                                         0,  no }, /* IANA */
  { 202, "nf_z_62-010_(1973)",                                0,  no }, /* IANA */
  { 202, "iso646-fr1",                                        0,  no }, /* IANA */
  { 202, "csiso25french",                                     0,  no }, /* IANA */
  { 203, "iso-ir-60",                                     20108,  no }, /* IANA */
  { 203, "ns_4551-1",                                     20108,  no }, /* IANA */
  { 203, "iso646-no",                                     20108,  no }, /* IANA */
  { 203, "no",                                            20108,  no }, /* IANA */
  { 203, "csiso60danishnorwegian",                        20108,  no }, /* IANA */
  { 203, "csiso60norwegian1",                             20108,  no }, /* IANA */
  { 203, "x-ia5-norwegian",                               20108,  no }, /* MICROSOFT */
  { 204, "iso-ir-61",                                         0,  no }, /* IANA */
  { 204, "ns_4551-2",                                         0,  no }, /* IANA */
  { 204, "iso646-no2",                                        0,  no }, /* IANA */
  { 204, "no2",                                               0,  no }, /* IANA */
  { 204, "csiso61norwegian2",                                 0,  no }, /* IANA */
  { 205, "pc8-danish-norwegian",                              0,  no }, /* IANA */
  { 205, "cspc8danishnorwegian",                              0,  no }, /* IANA */
  { 206, "pc8-turkish",                                       0,  no }, /* IANA */
  { 206, "cspc8turkish",                                      0,  no }, /* IANA */
  { 207, "iso-ir-16",                                         0,  no }, /* IANA */
  { 207, "pt",                                                0,  no }, /* IANA */
  { 207, "iso646-pt",                                         0,  no }, /* IANA */
  { 207, "csiso16portuguese",                                 0,  no }, /* IANA */
  { 208, "iso-ir-84",                                         0,  no }, /* IANA */
  { 208, "pt2",                                               0,  no }, /* IANA */
  { 208, "iso646-pt2",                                        0,  no }, /* IANA */
  { 208, "csiso84portuguese2",                                0,  no }, /* IANA */
  { 209, "ptcp154",                                           0,  no }, /* IANA */
  { 209, "csptcp154",                                         0,  no }, /* IANA */
  { 209, "pt154",                                             0,  no }, /* IANA */
  { 209, "cp154",                                             0,  no }, /* IANA */
  { 209, "cyrillic-asian",                                    0,  no }, /* IANA */
  { 210, "scsu",                                              0,  no }, /* IANA */
  { 211, "iso-ir-10",                                     20107,  no }, /* IANA */
  { 211, "sen_850200_b",                                  20107,  no }, /* IANA */
  { 211, "fi",                                            20107,  no }, /* IANA */
  { 211, "iso646-fi",                                     20107,  no }, /* IANA */
  { 211, "iso646-se",                                     20107,  no }, /* IANA */
  { 211, "se",                                            20107,  no }, /* IANA */
  { 211, "csiso10swedish",                                20107,  no }, /* IANA */
  { 211, "x-ia5-swedish",                                 20107,  no }, /* MICROSOFT */
  { 212, "iso-ir-11",                                         0,  no }, /* IANA */
  { 212, "sen_850200_c",                                      0,  no }, /* IANA */
  { 212, "iso646-se2",                                        0,  no }, /* IANA */
  { 212, "se2",                                               0,  no }, /* IANA */
  { 212, "csiso11swedishfornames",                            0,  no }, /* IANA */
  { 213, "shift_jis",                                       932,  no }, /* IANA */
  { 213, "ms_kanji",                                        932,  no }, /* IANA */
  { 213, "csshiftjis",                                      932,  no }, /* IANA */
  { 213, "shift-jis",                                       932,  no }, /* MICROSOFT */
  { 213, "x-ms-cp932",                                      932,  no }, /* MICROSOFT */
  { 213, "x-sjis",                                          932,  no }, /* MICROSOFT */
  { 214, "iso-ir-128",                                        0,  no }, /* IANA */
  { 214, "t.101-g2",                                          0,  no }, /* IANA */
  { 214, "csiso128t101g2",                                    0,  no }, /* IANA */
  { 215, "iso-ir-102",                                        0,  no }, /* IANA */
  { 215, "t.61-7bit",                                         0,  no }, /* IANA */
  { 215, "csiso102t617bit",                                   0,  no }, /* IANA */
  { 216, "iso-ir-103",                                        0,  no }, /* IANA */
  { 216, "t.61-8bit",                                         0,  no }, /* IANA */
  { 216, "t.61",                                              0,  no }, /* IANA */
  { 216, "csiso103t618bit",                                   0,  no }, /* IANA */
  { 217, "tis-620",                                         874,  no }, /* IANA */
  { 217, "windows-874",                                     874,  no }, /* MICROSOFT */
  { 217, "iso-8859-11",                                     874,  no }, /* MICROSOFT */
  { 217, "dos-874",                                         874,  no }, /* MICROSOFT */
  { 218, "unicode-1-1",                                       0,  no }, /* IANA */
  { 218, "csunicode11",                                       0,  no }, /* IANA */
  { 219, "unicode-1-1-utf-7",                             65000, yes }, /* IANA */
  { 219, "csunicode11utf7",                               65000, yes }, /* IANA */
  { 219, "x-unicode-2-0-utf-7",                           65000, yes }, /* MICROSOFT */
  { 220, "unknown-8bit",                                      0,  no }, /* IANA */
  { 220, "csunknown8bit",                                     0,  no }, /* IANA */
  { 221, "us-dk",                                             0,  no }, /* IANA */
  { 221, "csusdk",                                            0,  no }, /* IANA */
  { 222, "utf-16",                                         1200,  no }, /* IANA */
  { 222, "unicode",                                        1200,  no }, /* MICROSOFT */
  { 223, "utf-16be",                                       1201,  no }, /* IANA */
  { 223, "unicodefffe",                                    1201,  no }, /* MICROSOFT */
  { 224, "utf-16le",                                       1200,  no }, /* IANA */
  { 224, "unicode",                                        1200,  no }, /* MICROSOFT */
  { 225, "utf-32",                                            0,  no }, /* IANA */
  { 226, "utf-32be",                                          0,  no }, /* IANA */
  { 227, "utf-32le",                                          0,  no }, /* IANA */
  { 228, "utf-7",                                         65000, yes }, /* IANA */
  { 228, "x-unicode-2-0-utf-7",                           65000, yes }, /* MICROSOFT */
  { 229, "utf-8",                                         65001,  no }, /* IANA */
  { 229, "unicode-2-0-utf-8",                             65001,  no }, /* MICROSOFT */
  { 229, "unicode-1-1-utf-8",                             65001,  no }, /* MICROSOFT */
  { 229, "x-unicode-2-0-utf-8",                           65001,  no }, /* MICROSOFT */
  { 230, "ventura-international",                             0,  no }, /* IANA */
  { 230, "csventurainternational",                            0,  no }, /* IANA */
  { 231, "ventura-math",                                      0,  no }, /* IANA */
  { 231, "csventuramath",                                     0,  no }, /* IANA */
  { 232, "ventura-us",                                        0,  no }, /* IANA */
  { 232, "csventuraus",                                       0,  no }, /* IANA */
  { 233, "iso-ir-70",                                         0,  no }, /* IANA */
  { 233, "videotex-suppl",                                    0,  no }, /* IANA */
  { 233, "csiso70videotexsupp1",                              0,  no }, /* IANA */
  { 234, "viqr",                                              0,  no }, /* IANA */
  { 234, "csviqr",                                            0,  no }, /* IANA */
  { 235, "viscii",                                            0,  no }, /* IANA */
  { 235, "csviscii",                                          0,  no }, /* IANA */
  { 236, "windows-1250",                                   1250,  no }, /* IANA */
  { 236, "x-cp1250",                                       1250,  no }, /* MICROSOFT */
  { 237, "windows-1251",                                   1251,  no }, /* IANA */
  { 237, "x-cp1251",                                       1251,  no }, /* MICROSOFT */
  { 238, "windows-1252",                                   1252,  no }, /* IANA */
  { 238, "x-ansi",                                         1252,  no }, /* MICROSOFT */
  { 239, "windows-1253",                                   1253,  no }, /* IANA */
  { 240, "windows-1254",                                   1254,  no }, /* IANA */
  { 241, "windows-1255",                                   1255,  no }, /* IANA */
  { 242, "windows-1256",                                   1256,  no }, /* IANA */
  { 242, "cp1256",                                         1256,  no }, /* MICROSOFT */
  { 243, "windows-1257",                                   1257,  no }, /* IANA */
  { 244, "windows-1258",                                   1258,  no }, /* IANA */
  { 245, "windows-31j",                                     932,  no }, /* IANA */
  { 245, "cswindows31j",                                    932,  no }, /* IANA */
  { 245, "shift-jis",                                       932,  no }, /* MICROSOFT */
  { 245, "x-ms-cp932",                                      932,  no }, /* MICROSOFT */
  { 245, "x-sjis",                                          932,  no }, /* MICROSOFT */
  { 246, "dos-720",                                         720,  no }, /* MICROSOFT */
  { 247, "euc-cn",                                        51936,  no }, /* MICROSOFT */
  { 248, "ibm737",                                          737,  no }, /* MICROSOFT */
  { 249, "johab",                                          1361,  no }, /* MICROSOFT */
  { 250, "x-chinese-cns",                                 20000,  no }, /* MICROSOFT */
  { 251, "x-chinese-eten",                                20002,  no }, /* MICROSOFT */
  { 252, "x-ebcdic-cyrillicserbianbulgarian",             21025,  no }, /* MICROSOFT */
  { 253, "x-ebcdic-greekmodern",                            875,  no }, /* MICROSOFT */
  { 254, "x-ebcdic-japaneseandjapaneselatin",             50939,  no }, /* MICROSOFT */
  { 255, "x-ebcdic-japaneseandkana",                      50930,  no }, /* MICROSOFT */
  { 256, "x-ebcdic-japaneseanduscanada",                  50931,  no }, /* MICROSOFT */
  { 257, "x-ebcdic-koreanandkoreanextended",              50933,  no }, /* MICROSOFT */
  { 258, "x-ebcdic-koreanextended",                       20833,  no }, /* MICROSOFT */
  { 259, "x-ebcdic-simplifiedchinese",                    50935,  no }, /* MICROSOFT */
  { 260, "x-ebcdic-traditionalchinese",                   50937,  no }, /* MICROSOFT */
  { 261, "x-euc-cn",                                      51936,  no }, /* MICROSOFT */
  { 262, "x-europa",                                      29001,  no }, /* MICROSOFT */
  { 263, "x-iscii-as",                                    57006,  no }, /* MICROSOFT */
  { 264, "x-iscii-be",                                    57003,  no }, /* MICROSOFT */
  { 265, "x-iscii-de",                                    57002,  no }, /* MICROSOFT */
  { 266, "x-iscii-gu",                                    57010,  no }, /* MICROSOFT */
  { 267, "x-iscii-ka",                                    57008,  no }, /* MICROSOFT */
  { 268, "x-iscii-ma",                                    57009,  no }, /* MICROSOFT */
  { 269, "x-iscii-or",                                    57007,  no }, /* MICROSOFT */
  { 270, "x-iscii-pa",                                    57011,  no }, /* MICROSOFT */
  { 271, "x-iscii-ta",                                    57004,  no }, /* MICROSOFT */
  { 272, "x-iscii-te",                                    57005,  no }, /* MICROSOFT */
  { 273, "x-mac-arabic",                                  10004,  no }, /* MICROSOFT */
  { 274, "x-mac-ce",                                      10029,  no }, /* MICROSOFT */
  { 275, "x-mac-chinesesimp",                             10008,  no }, /* MICROSOFT */
  { 276, "x-mac-chinesetrad",                             10002,  no }, /* MICROSOFT */
  { 277, "x-mac-cyrillic",                                10007,  no }, /* MICROSOFT */
  { 278, "x-mac-greek",                                   10006,  no }, /* MICROSOFT */
  { 279, "x-mac-hebrew",                                  10005,  no }, /* MICROSOFT */
  { 280, "x-mac-icelandic",                               10079,  no }, /* MICROSOFT */
  { 281, "x-mac-japanese",                                10001,  no }, /* MICROSOFT */
  { 282, "x-mac-korean",                                  10003,  no }, /* MICROSOFT */
  { 283, "x-mac-turkish",                                 10081,  no }, /* MICROSOFT */

  /* final entry */
  {   0, NULL,                                                0,  no }
};

uint TY_(GetEncodingIdFromName)(ctmbstr name)
{
    uint i;

    for (i = 0; charsetInfo[i].id; ++i)
        if (TY_(tmbstrcasecmp)(name, charsetInfo[i].charset) == 0)
            return charsetInfo[i].id;

    return 0;
}

uint TY_(GetEncodingIdFromCodePage)(uint cp)
{
    uint i;

    for (i = 0; charsetInfo[i].id; ++i)
        if (cp == charsetInfo[i].codepage)
            return charsetInfo[i].id;

    return 0;
}

uint TY_(GetEncodingCodePageFromName)(ctmbstr name)
{
    uint i;

    for (i = 0; charsetInfo[i].id; ++i)
        if (TY_(tmbstrcasecmp)(name, charsetInfo[i].charset) == 0)
            return charsetInfo[i].codepage;

    return 0;
}

uint TY_(GetEncodingCodePageFromId)(uint id)
{
    uint i;

    for (i = 0; charsetInfo[i].id; ++i)
        if (id == charsetInfo[i].id)
            return charsetInfo[i].codepage;

    return 0;
}

ctmbstr TY_(GetEncodingNameFromId)(uint id)
{
    uint i;

    for (i = 0; charsetInfo[i].id; ++i)
        if (id == charsetInfo[i].id)
            return charsetInfo[i].charset;

    return NULL;
}

ctmbstr TY_(GetEncodingNameFromCodePage)(uint cp)
{
    uint i;

    for (i = 0; charsetInfo[i].id; ++i)
        if (cp == charsetInfo[i].codepage)
            return charsetInfo[i].charset;

    return NULL;
}

/*
 * local variables:
 * mode: c
 * indent-tabs-mode: nil
 * c-basic-offset: 4
 * eval: (c-set-offset 'substatement-open 0)
 * end:
 */
