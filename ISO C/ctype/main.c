#include <ctype.h>
#include <stdio.h>

int main(void) {
  /*
   * 测试字符集合
   *
   * A  : 大写字母
   * a  : 小写字母
   * 5  : 数字
   * @  : 标点符号
   * ' ' : 空格
   * \n : 控制字符
   * F  : 十六进制字符
   */
  unsigned char test_chars[] = {'A', 'a', '5', '@', ' ', '\n', 'F'};

  int n = sizeof(test_chars) / sizeof(test_chars[0]);

  for (int i = 0; i < n; i++) {

    /*
     * ctype 函数参数必须：
     *   EOF
     *   或 unsigned char 范围
     *
     * 所以这里使用 unsigned char
     */
    unsigned char c = test_chars[i];

    printf("=====================================\n");

    /*
     * 对于不可打印字符单独处理
     */
    if (isprint(c))
      printf("Character: '%c'\n", c);
    else
      printf("Character: non-printable (ASCII=%d)\n", c);

    printf("ASCII code: %d\n\n", c);

    /*
     * isalnum()
     * 是否是字母或数字
     */
    printf("isalnum : %s\n", isalnum(c) ? "true" : "false");

    /*
     * isalpha()
     * 是否是字母
     */
    printf("isalpha : %s\n", isalpha(c) ? "true" : "false");

    /*
     * iscntrl()
     * 是否是控制字符
     * 例如:
     *   \n \t \r ESC
     */
    printf("iscntrl : %s\n", iscntrl(c) ? "true" : "false");

    /*
     * isdigit()
     * 是否是十进制数字
     * 0-9
     */
    printf("isdigit : %s\n", isdigit(c) ? "true" : "false");

    /*
     * isgraph()
     * 是否是“可见字符”
     * 不包括空格
     */
    printf("isgraph : %s\n", isgraph(c) ? "true" : "false");

    /*
     * islower()
     * 是否是小写字母
     */
    printf("islower : %s\n", islower(c) ? "true" : "false");

    /*
     * isprint()
     * 是否可打印
     * 包括空格
     */
    printf("isprint : %s\n", isprint(c) ? "true" : "false");

    /*
     * ispunct()
     * 是否是标点符号
     * 例如:
     *   @ ! ? , .
     */
    printf("ispunct : %s\n", ispunct(c) ? "true" : "false");

    /*
     * isspace()
     * 是否是空白字符
     * 例如:
     *   space \t \n
     */
    printf("isspace : %s\n", isspace(c) ? "true" : "false");

    /*
     * isupper()
     * 是否是大写字母
     */
    printf("isupper : %s\n", isupper(c) ? "true" : "false");

    /*
     * isxdigit()
     * 是否是十六进制字符
     * 0-9 a-f A-F
     */
    printf("isxdigit: %s\n", isxdigit(c) ? "true" : "false");

    printf("\n");
  }

  return 0;
}