#include <iostream>
#include <vector>
using namespace std; 
template <class T>

class VectorQuickSorter {
private:
	void swap_em(vector<T> &vec, int idx1, int idx2);
public:
	VectorQuickSorter();
	~VectorQuickSorter();
	
	void quick_sort_3way(vector<T> &vec, int loIndex, int hiIndex);
	void quick_sort_dual_pivot(vector<T> &vec, int loIndex, int hiIndex);
};

template <class T>
VectorQuickSorter<T>::VectorQuickSorter() {

}

template <class T>
VectorQuickSorter<T>::~VectorQuickSorter() {

}

template <class T>
void VectorQuickSorter<T>::swap_em(vector<T> &vec, int idx1, int idx2) {
	T tempSwap = vec[idx1];
	vec[idx1] = vec[idx2];
	vec[idx2] = tempSwap;
}




template <class T>
void VectorQuickSorter<T>::quick_sort_dual_pivot(vector<T> &vec, int loIndex, int hiIndex) {
	if (hiIndex <= loIndex) return;
	if (vec[loIndex] > vec[hiIndex]) {
		swap_em(vec, loIndex, hiIndex);
	}

	int i = loIndex + 1;
	int lt = loIndex + 1;
	int gt = hiIndex - 1;

	while (i <= gt) {
		if (vec[i] < vec[loIndex]) {
			swap_em(vec, i++, lt++);
		}
		else if (vec[hiIndex] < vec[i]) {
			swap_em(vec, i, gt--);
		}
		else {
			i++;
		}
	}

	swap_em(vec, loIndex, --lt);
	swap_em(vec, hiIndex, ++gt);

	quick_sort_dual_pivot(vec, loIndex, lt - 1);
	if (vec[lt] < vec[gt]) quick_sort_dual_pivot(vec, lt + 1, gt - 1);
	quick_sort_dual_pivot(vec, gt + 1, hiIndex);
}

template <class T>
void VectorQuickSorter<T>::quick_sort_3way(vector<T> &vec, int loIndex, int hiIndex) {
	if (hiIndex <= loIndex) return;

	int lt = loIndex;
	int gt = hiIndex;
	int i = loIndex + 1;

	int pivotIndex = loIndex;
	T pivotValue = vec[pivotIndex];

	while (i <= gt) {
		if (vec[i] < pivotValue) {
			swap_em(vec, i++, lt++);
		}
		else if (pivotValue < vec[i]) {
			swap_em(vec, i, gt--);
		}
		else {
			i++;
		}
	}

	quick_sort_3way(vec, loIndex, lt - 1);
	quick_sort_3way(vec, gt + 1, hiIndex);
}


#pragma once
