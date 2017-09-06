#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

///*
//arr[start+1...end]满足最大堆的定义，
//将arr[start]加入到最大堆arr[start+1...end]中，
//调整arr[start]的位置，使arr[start...end]也成为最大堆
//注：由于数组从0开始计算序号，也就是二叉堆的根节点序号为0，
//因此序号为i的左右子节点的序号分别为2i+1和2i+2
//start为当前双亲结点
//*/

//void HeapAdjustDown(int arr[], int start, int end)
//{
//	int temp = arr[start];  //保存当前节点  
//	int i = 2 * start + 1;      //该节点的左孩子在数组中的位置序号  
//
//	//判断右孩子是否超出了数组的长度,如果超出表示不存在
//	while (i <= end)
//	{
//		//i + 1 <= end判断有无右孩子 如果存在右孩子找出左右孩子中最大的那个  
//		if (i + 1 <= end && arr[i + 1] > arr[i])
//		{
//			//指向较大的右孩子
//			i++;
//		}			
//		//如果符合堆的定义，则不用调整位置  temp为当前树的根节点(start)
//		if (arr[i] <= temp)
//		{
//			break;
//		}
//			
//		//最大的子节点向上移动，替换掉其父节点  
//		arr[start] = arr[i];
//		start = i;
//		//i指向当前树的根节点(start)的右孩子的右孩子(如果存在右孩子继续判断是否符合最大堆的定义)
//		i = 2 * start + 1;
//	}
//	arr[start] = temp;
//}
//
///*
//堆排序后的顺序为从小到大
//因此需要建立最大堆
//*/
//void HeapSort(int arr[], int len)
//{
//	int i;
//	//把数组建成为最大堆  
//	//第一个非叶子节点的位置序号为len/2-1  从这个非叶子结点开始一次向前对每个i开始的子树进行判断是否符合最大堆的定义,全部判断完成后整个树满足最大堆的定义
//	for (i = len / 2 - 1; i >= 0; i--)
//	{
//		HeapAdjustDown(arr, i, len - 1);
//	}
//		
//	//进行堆排序  
//	for (i = len - 1; i>0; i--)
//	{
//		//堆顶元素和最后一个元素交换位置，  
//		//这样最后的一个位置保存的是最大的数，  
//		//每次循环依次将次大的数值在放进其前面一个位置，  
//		//这样得到的顺序就是从小到大  
//		int temp = arr[i];
//		arr[i] = arr[0];
//		arr[0] = temp;
//		//将arr[0...i-1]重新调整为最大堆  
//		HeapAdjustDown(arr, 0, i - 1);
//	}
//}

//参数s为当前双亲结点
void HeapAdjust(int a[], int s, int n)
{
	int i,temp;
	//temp为第一个非叶结点
	temp = a[s];
	//2*s+1为s结点的左孩子结点, i <= n 表示孩子结点要在数组的范围内,超出表示没有孩子结点
	for (i = 2*s+1; i <= n; i=i*2+1)
	{
		//如果左孩子小于右孩子则选择右孩子
		if (i < n && a[i] < a[i + 1])
		{
			i++;
		}
		//如果双亲节点大于他的孩子结点符合大根堆定义无需交换跳出循环
		if (temp >= a[i])
		{
			break;
		}

		a[s] = a[i];
		s = i;
	}

	a[s] = temp;
}

void HeapSort(int a[], int n)
{
	int i, temp;
	//第一个非叶子节点的位置序号为 n/2 -1 从第一个非叶子节点依次往前调整堆
	//
	for (i = n/2 -1 ; i >=0; i--)
	{
		HeapAdjust(a, i, n -1);
	}
	//完成上面的步骤树的结构已经符合大顶堆的定义了

	//进行排序
	for ( i = n-1; i >=0; i--)
	{
		//堆顶元素和最有一个元素交换位置(最大值放在了数组的最后)
		temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		//排除最后一个最大的元素重新对剩余的数据进行大顶堆的重构
		//注意和上面堆的初始化构造大顶堆的区别,上面的要从第一个非叶子节点的位置序号为 n/2 -1依次往前进行调整直到根节点为止
		//本次的循环所操纵的堆除了第一个和最后一个进行交换(最大值和最小值)外其他各个结点都符合大根堆的定义,这样只要从根节点(最小值)开始依次遍历他的孩子结点,直到把最小的那个元素移动到叶节点为止
		//本次循环中经过最大值和最小值交换,根节点是最小值,他的其中一个孩子结点一定是当前树中的最大值,依次遍历后再把最小值交换到叶节点最小值的位置,所以每次循环,树都符合大根堆的规定.
		HeapAdjust(a, 0, i-1);
	}
}
int main()
{
	int i;//;a[10] = { 5, 2, 6, 0, 3, 9, 1, 7, 4, 8 };
	int a[10] = { 5, 2, 6, 0, 3, 9, 1, 7, 4, 8 };
	//int a[10] = { 1, 0, 2, 3, 4, 5, 6, 7, 8, 9 };
	HeapSort(a, 10);
	
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", a[i]);
	}

	system("pause");
	return 0;
}
#endif