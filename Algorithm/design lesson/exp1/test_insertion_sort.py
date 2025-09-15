import unittest
from InsertionSort import insertion_sort

class TestInsertionSort(unittest.TestCase):
    def test_empty_list(self):
        input_list = []
        expected = []
        result = insertion_sort(input_list)
        print(f"测试用例: 空列表 -> {input_list}, 预期: {expected}")
        self.assertEqual(result, expected)

    def test_single_element(self):
        input_list = [5]
        expected = [5]
        result = insertion_sort(input_list)
        print(f"测试用例: 单元素列表 -> {input_list}, 预期: {expected}")
        self.assertEqual(result, expected)

    def test_sorted_list(self):
        input_list = [1, 2, 3, 4, 5]
        expected = [1, 2, 3, 4, 5]
        result = insertion_sort(input_list)
        print(f"测试用例: 已排序列表 -> {input_list}, 预期: {expected}")
        self.assertEqual(result, expected)

    def test_reverse_sorted(self):
        input_list = [5, 4, 3, 2, 1]
        expected = [1, 2, 3, 4, 5]
        result = insertion_sort(input_list)
        print(f"测试用例: 逆序列表 -> {input_list}, 预期: {expected}")
        self.assertEqual(result, expected)

    def test_random_order(self):
        input_list = [3, 1, 4, 1, 5, 9, 2, 6]
        expected = [1, 1, 2, 3, 4, 5, 6, 9]
        result = insertion_sort(input_list)
        print(f"测试用例: 乱序列表 -> {input_list}, 预期: {expected}")
        self.assertEqual(result, expected)

    def test_duplicate_elements(self):
        input_list = [1, 2, 2, 3, 3]
        expected = [1, 2, 2, 3, 3]
        result = insertion_sort(input_list)
        print(f"测试用例: 包含重复元素列表 -> {input_list}, 预期: {expected}")
        self.assertEqual(result, expected)

    def test_negative_numbers(self):
        input_list = [-8, -5, -2, -1, 0]
        expected = [-8, -5, -2, -1, 0]
        result = insertion_sort(input_list)
        print(f"测试用例: 包含负数列表 -> {input_list}, 预期: {expected}")
        self.assertEqual(result, expected)

    def test_mixed_numbers(self):
        input_list = [-9, -3, 0, 1, 5, 7]
        expected = [-9, -3, 0, 1, 5, 7]
        result = insertion_sort(input_list)
        print(f"测试用例: 混合数字列表 -> {input_list}, 预期: {expected}")
        self.assertEqual(result, expected)

if __name__ == '__main__':
    unittest.main()