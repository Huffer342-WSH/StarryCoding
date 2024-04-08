#include <bits/stdc++.h>

using ll = long long;
const int N = 2e5 + 10;

int a[N];
int buf[N];
#include <stdbool.h>
struct deque {
	uint32_t back; //指向最后面的数
	uint32_t front; //指向最前面的数
	uint32_t cap; //最大容量
	uint8_t elmBytes; //元素大小
	void *pData; //空数组，malloc时额外申请空间
};
static inline uint32_t moveRight(uint32_t i, uint32_t size)
{
	i++;
	return i >= size ? i - size : i;
}
static inline uint32_t moveLeft(uint32_t i, uint32_t size)
{
	return i ? i - 1 : size - 1;
}
void deque_newStatic(struct deque *dq, uint32_t cap, uint8_t elmBytes, void *bufAddr)
{
	dq->cap = cap;
	dq->back = 0;
	dq->front = 1;
	dq->elmBytes = elmBytes;
	dq->pData = bufAddr;
}
int deque_isEmpty(struct deque *dq)
{
	return dq->back == moveLeft(dq->front, dq->cap);
}

void deque_front(struct deque *dq, void *res)
{
	memcpy(res, dq->pData + dq->front * dq->elmBytes, dq->elmBytes);
}
void deque_back(struct deque *dq, void *res)
{
	memcpy(res, dq->pData + dq->back * dq->elmBytes, dq->elmBytes);
}

void deque_pushBack(struct deque *dq, void *pElm)
{
	dq->back = moveRight(dq->back, dq->cap);
	memcpy(dq->pData + dq->back * dq->elmBytes, pElm, dq->elmBytes);
}

void deque_popFront(struct deque *dq)
{
	dq->front = moveRight(dq->front, dq->cap);
}
void deque_popBack(struct deque *dq)
{
	dq->back = moveLeft(dq->back, dq->cap);
}

void solve1(int a[], int n, int k)
{
	struct deque dq;
	deque_newStatic(&dq, N, sizeof(int), buf);

	for (int i = 0; i < n; i++) {
		while (!deque_isEmpty(&dq)) {
			int x;
			deque_front(&dq, &x);
			if (x <= i - k) {
				deque_popFront(&dq);
			} else {
				break;
			}
		}
		while (!deque_isEmpty(&dq)) {
			int x;
			deque_back(&dq, &x);
			if (a[x] >= a[i]) {
				deque_popBack(&dq);
			} else {
				break;
			}
		}
		deque_pushBack(&dq, &i);
		if (i >= k - 1) {
			int x;
			deque_front(&dq, &x);
			std::cout << a[x] << ' ';
		}
	}
}
void solve2(int a[], int n, int k)
{
	using namespace std;
	std::deque<int> dq;
	for (int i = 0; i < n; i++) {
		while (!dq.empty() && dq.front() <= i - k)
			dq.pop_front();
		while (!dq.empty() && a[dq.back()] <= a[i])
			dq.pop_back();
		dq.push_back(i);
		if (i >= k - 1)
			cout << a[dq.front()] << ' ';
	}
}
int main(int argc, char const *argv[])
{
	using namespace std;
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	queue<int> que;
	multiset<int> ms;
	cin >> n >> k;
	for (size_t i = 0; i < n; i++) {
		cin >> a[i];
	}
	solve2(a, n, k);
	cout << endl;
	solve1(a, n, k);

	return 0;
}
