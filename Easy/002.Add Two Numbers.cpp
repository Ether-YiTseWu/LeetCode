class Solution // 創建 Solution 這個類別
{
public: // 設定下列函數與變數為 Public
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) // 設定成員函數
	{
		if (l1 == NULL and l2 == NULL) return NULL;
		else if (l1 == NULL) return l2;
		else if (l2 == NULL) return l1;
		/* 以上三行 Code 是確保，若函數的輸入參數有任何一個為 NULL
 		的話，就直接回傳 NULL；或回傳另一不為 NULL 的 LinkedList。
 		如此一來，便不必進行下列的計算。這些 Code 除了考慮到題
 		目測資可能為 NULL 以外，也考慮到遞迴算法的回傳需求。 */ 
 		
		int a = l1->val + l2->val;								// 對兩個 LinkedList 中的第一個節點資料做相加。
		ListNode *p = new ListNode(a % 10);						// 宣告一個 LinkedList，p。p 只有一筆資料，該資料為 a % 10。
		p->next = addTwoNumbers(l1->next,l2->next);		
		/* 利用遞迴算法呼叫自己，以此來設定 p 後面節點的資料值大小。
 		函數中的引數是最原始輸入 l1、l2 後面的節點位址。不過由於
 		遞迴特性，下次執行時的輸入會是 l1、l2 後面再後面的節點位
 		址。之後以此類推，因此 l1、l2 中所有的節點都會被 RUN 到，
		 意即會做每個位數的資料相加、或只回傳多出的位數。 */
		if (a >= 10) 
			p->next = addTwoNumbers(p->next, new ListNode(1));	
		/* 再次利用遞迴算法呼叫自己，以把進位的情況也考慮進去(上個
 		遞迴沒有考慮進位)。若兩個 LinkedList 中的第一個節點資料相
 		加大於 10，則把 p 後面節點的資料值大小加一。該遞迴算法第
 		一次執行的時間點，是在前一個遞迴算法中，addTwoNumbers
 		的兩個引數都不為 NULL 的時候。最後一次執行則是在答案要
 		算出來的前一刻(若 l1、l2 的第一個數值相加大於 10 的話)。 */
		return p;
	}
};
