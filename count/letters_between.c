/**
 * time: 2024.9.13
 * issues: calculate the shortest path between the two given letters
 *
 * solves: ascii 自动转换
 */
#include <stdio.h>

int main(void) {
  char start, target;  // 起始字母和目标字母 只考虑小写
  int forward_steps, backward_steps;  // 到达目标字符需要前进和后退的步数
  int temp_distance;  // 计算每次距离原点字母 a(97) 的距离

  printf("Enter the letter, start and target: ");
  scanf("%c%*c%c", &start, &target);  // 第二个数可以另起一行输入

  forward_steps = ((target + 26) - start) % 26;
  backward_steps = ((start + 26) - target) % 26;

  // 比较两条路线，哪个步数较短显示哪个
  if (forward_steps <= backward_steps) {
    for (int i = 0; i <= forward_steps; i++) {
      temp_distance = ((start + i) - 'a') % 26;
      printf("%c", 97 + temp_distance);  // 从 a 往后找到这次的字母
    }
  } else {
    start += 26;  // 起始字母先移到下一个周期里 防止为负
    for (int i = 0; i <= backward_steps; i++) {
      temp_distance = ((start - i) - 'a') % 26;
      printf("%c", 'a' + temp_distance);
    }
  }

  puts("");
  return 0;
}