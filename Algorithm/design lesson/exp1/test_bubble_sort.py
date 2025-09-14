import unittest
from BubbleSort import BubbleSort, swap  # 导入冒泡排序函数和辅助交换函数

class TestBubbleSort(unittest.TestCase):

    def test_empty_list(self):
        # 测试空列表
        arr = []
        self.assertEqual(BubbleSort(arr), [])
        print(f"测试用例: 空列表 -> {arr}, 预期: []")

    def test_single_element_list(self):
        # 测试单元素列表
        arr = [5]
        self.assertEqual(BubbleSort(arr), [5])
        print(f"测试用例: 单元素列表 -> {arr}, 预期: [5]")

    def test_already_sorted_list(self):
        # 测试已排序列表
        arr = [1, 2, 3, 4, 5]
        self.assertEqual(BubbleSort(arr), [1, 2, 3, 4, 5])
        print(f"测试用例: 已排序列表 -> {arr}, 预期: [1, 2, 3, 4, 5]")

    def test_reverse_sorted_list(self):
        # 测试逆序列表
        arr = [5, 4, 3, 2, 1]
        self.assertEqual(BubbleSort(arr), [1, 2, 3, 4, 5])
        print(f"测试用例: 逆序列表 -> {arr}, 预期: [1, 2, 3, 4, 5]")

    def test_unsorted_list(self):
        # 测试乱序列表
        arr = [3, 1, 4, 1, 5, 9, 2, 6]
        self.assertEqual(BubbleSort(arr), [1, 1, 2, 3, 4, 5, 6, 9])
        print(f"测试用例: 乱序列表 -> {arr}, 预期: [1, 1, 2, 3, 4, 5, 6, 9]")

    def test_list_with_duplicates(self):
        # 测试包含重复元素的列表
        arr = [3, 2, 3, 1, 2]
        self.assertEqual(BubbleSort(arr), [1, 2, 2, 3, 3])
        print(f"测试用例: 包含重复元素列表 -> {arr}, 预期: [1, 2, 2, 3, 3]")

    def test_negative_numbers(self):
        # 测试包含负数的列表
        arr = [-5, -2, -8, 0, -1]
        self.assertEqual(BubbleSort(arr), [-8, -5, -2, -1, 0])
        print(f"测试用例: 包含负数列表 -> {arr}, 预期: [-8, -5, -2, -1, 0]")

    def test_mixed_numbers(self):
        # 测试包含正数、负数和零的列表
        arr = [7, -3, 0, 1, -9, 5]
        self.assertEqual(BubbleSort(arr), [-9, -3, 0, 1, 5, 7])
        print(f"测试用例: 混合数字列表 -> {arr}, 预期: [-9, -3, 0, 1, 5, 7]")

    def test_swap_function(self):
        # 测试辅助交换函数
        arr = [1, 2]
        swap(0, 1, arr)
        self.assertEqual(arr, [2, 1])
        print(f"测试用例: swap函数 -> 原始[1, 2], 交换后: {arr}, 预期: [2, 1]")

if __name__ == '__main__':
    unittest.main(argv=['first-arg-is-ignored'], exit=False)