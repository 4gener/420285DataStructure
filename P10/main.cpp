#include <iostream>
#include <vector>

int count = 0;

void generateRandom(int num, std::vector<int> &nums) {
    nums.resize(num);
    for (int i = 0; i < num; i++) {
        nums[i] = i;
    };
    std::random_shuffle(nums.begin(), nums.end());
}

void bubbleSort(std::vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size() - i; j++) {
            if (nums[j] > nums[j + 1]) {
                std::swap(nums[j], nums[j + 1]);
                count++;
            }
        }
    }
}

void selectSort(std::vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        int min = nums[i];
        int minIndex = i;
        for (int j = i; j < nums.size(); j++) {
            if (nums[j] < min) {
                min = nums[j];
                minIndex = j;
            }
        }
        std::swap(nums[i], nums[minIndex]);
        count++;
    }
}

void insertSort(std::vector<int> &nums) {
    std::vector<int> insertedNums;
    for (auto num:nums) {
        int ins = num;
        if (insertedNums.empty()) {
            insertedNums.push_back(ins);
        }
        else if (ins > insertedNums.back()) {
            insertedNums.push_back(ins);
            count++;
        }
        else {
            for (int i = 0; i < insertedNums.size(); i++) {
                if (insertedNums[i] >= ins) {
                    insertedNums.resize(insertedNums.size() + 1);
                    for (auto j = insertedNums.size(); j > i; j--) {
                        insertedNums[j] = insertedNums[j - 1];
                        count++;
                    }
                    insertedNums[i] = ins;
                    count++;
                    break;
                }
            }
        }
    }
}

void shellSort(std::vector<int> nums) {
    count = 0;
    for (int gap = nums.size() / 3 + 1; gap >= 1; gap = gap / 3 + 1) {   // 不同gap
        for (int i = 0; i < gap; i++) {     // 某种gap下的不同组
            for (int j = i; j < nums.size(); j += gap) {    // 组内遍历
                if (j - gap >= 0) {
                    if (nums[j] < nums[j - gap]) {
                        for (int m = i; m < j; m += gap) {      // 寻找插入点
                            if (nums[m] >= nums[j]) {
                                int ins = nums[j];
                                for (int n = j; n > m; n -= gap) {
                                    nums[n] = nums[n - gap];
                                    count++;
                                }
                                nums[m] = ins;
                                count++;
                                break;
                            }
                        }
                    }

                }
            }
        }
        if (gap == 1)
            break;
    }
}

int partition(int low, int high, std::vector<int> &nums) {
    int pivotPos = low;
    int pivot = nums[low];
    for (int i = low + 1; i <= high; i++) {
        if (nums[i] < pivot) {
            pivotPos++;
            if (pivotPos != i) {
                std::swap(nums[pivotPos], nums[i]);
                count++;
            }
        }
    }
    std::swap(nums[pivotPos], nums[low]);
    count++;
    return pivotPos;
}

void quickSort(int low, int high, std::vector<int> &nums) {
    if (low < high) {
        int pivotPos = partition(low, high, nums);
        quickSort(pivotPos + 1, high, nums);
        quickSort(low, pivotPos - 1, nums);
    }
}

void triggerQuickSort(std::vector<int> nums) {
    quickSort(0, nums.size() - 1, nums);
}

void siftDown(int parent, int max, std::vector<int> &nums) {
    int child = 2 * parent + 1;
    while (child <= max) {
        if (child < max && nums[child] < nums[child + 1]) {
            child++;
        }
        if (nums[parent] >= nums[child]) {
            break;
        }
        else {
            std::swap(nums[parent], nums[child]);
            count++;
            parent = child;
            child = 2 * child + 1;
        }
    }
}

void heapSort(std::vector<int> nums) {
    for (int i = (nums.size() - 2) / 2; i >= 0; i--) {
        siftDown(i, nums.size() - 1, nums);
    }
    for (int i = nums.size() - 1; i > 0; i--) {
        std::swap(nums[0], nums[i]);
        count++;
        siftDown(0, i - 1, nums);
    }
}

void merge(int low, int mid, int high, std::vector<int> &nums) {
    std::vector<int> tempNums(nums);
    int l1 = low;
    int l2 = mid + 1;
    for (int i = low; i <= high; i++) {
        if (tempNums[l1] <= tempNums[l2]) {
            nums[i] = tempNums[l1];
            count++;
            l1++;
            if (l1 > mid) {
                i++;
                for (int j = 0; j <= high - l2; j++) {
                    nums[i + j] = nums[l2 + j];
                    count++;
                }
                break;
            }
        }
        else {
            nums[i] = tempNums[l2];
            count++;
            l2++;
            if (l2 > high) {
                i++;
                for (int j = 0; j <= mid - l1; j++) {
                    nums[i + j] = tempNums[l1 + j];
                    count++;
                }
                break;
            }
        }
    }
}

void mergeSort(int low, int high, std::vector<int> &nums) {
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(mid + 1, high, nums);
    mergeSort(low, mid, nums);
    merge(low, mid, high, nums);
}

void triggerMergeSort(std::vector<int> nums) {
    mergeSort(0, nums.size() - 1, nums);
}

void countSort(int exp, std::vector<int> &nums) {
    std::vector<int> range(10, 0);
    std::vector<int> replaceNums(nums.size());

    for (auto &num:nums) {
        range[(num / exp) % 10]++;
    }

    range[0]--;
    for (int i = 1; i < nums.size(); i++) {
        range[i] += range[i - 1];
    }

    for (auto &num:nums) {
        replaceNums[range[(num / exp) % 10]] = num;
        count++;
        range[(num / exp) % 10]--;
    }

    nums = replaceNums;
}

void radixSort(std::vector<int> nums) {
    int max = *(std::max_element(std::begin(nums), std::end(nums)));
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(exp, nums);
    }
}

int main() {
    std::vector<int> nums;
    std::cout << "**\t\t\t  排序算法比较\t\t\t\t**\n"
              << "==========================================\n"
              << "**\t\t\t1 --- 冒泡排序\t\t\t\t**\n"
              << "**\t\t\t2 --- 选择排序\t\t\t\t**\n"
              << "**\t\t\t3 --- 直接插入排序\t\t\t**\n"
              << "**\t\t\t4 --- 希尔排序\t\t\t\t**\n"
              << "**\t\t\t5 --- 快速排序\t\t\t\t**\n"
              << "**\t\t\t6 --- 堆排序\t\t\t\t\t**\n"
              << "**\t\t\t7 --- 归并排序\t\t\t\t**\n"
              << "**\t\t\t8 --- 基数排序\t\t\t\t**\n"
              << "**\t\t\t9 --- 退出程序\t\t\t\t**\n"
              << "==========================================\n"
              << "请选择要产生的随机数的个数:";
    int n;
    std::cin >> n;
    generateRandom(n, nums);


    while (1) {
        int command = 0;
        count = 0;
        std::cout << "请选择排序算法：";
        std::cin >> command;
        auto ts = clock();
        switch (command) {
            case 1:
                bubbleSort(nums);
                break;
            case 2:
                selectSort(nums);
                break;
            case 3:
                insertSort(nums);
                break;
            case 4:
                shellSort(nums);
                break;
            case 5:
                triggerQuickSort(nums);
                break;
            case 6:
                heapSort(nums);
                break;
            case 7:
                triggerMergeSort(nums);
                break;
            case 8:
                radixSort(nums);
                break;
            case 9:
                std::cout << "再见～" << std::endl;
                return 0;
            default:
                std::cout << "请输入有效排序算法！" << std::endl << std::endl;
        }
        auto te = clock();
        if (count) {
            std::cout << "用时" << float(te - ts) / CLOCKS_PER_SEC << "秒" << std::endl
                      << "总共交换" << count << "次" << std::endl << std::endl;
        }
    }
}

