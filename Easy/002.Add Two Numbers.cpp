class Solution // �Ы� Solution �o�����O
{
public: // �]�w�U�C��ƻP�ܼƬ� Public
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) // �]�w�������
	{
		if (l1 == NULL and l2 == NULL) return NULL;
		else if (l1 == NULL) return l2;
		else if (l2 == NULL) return l1;
		/* �H�W�T�� Code �O�T�O�A�Y��ƪ���J�ѼƦ�����@�Ӭ� NULL
 		���ܡA�N�����^�� NULL�F�Φ^�ǥt�@���� NULL �� LinkedList�C
 		�p���@�ӡA�K�����i��U�C���p��C�o�� Code ���F�Ҽ{���D
 		�ش���i�ର NULL �H�~�A�]�Ҽ{�컼�j��k���^�ǻݨD�C */ 
 		
		int a = l1->val + l2->val;								// ���� LinkedList �����Ĥ@�Ӹ`�I��ư��ۥ[�C
		ListNode *p = new ListNode(a % 10);						// �ŧi�@�� LinkedList�Ap�Cp �u���@����ơA�Ӹ�Ƭ� a % 10�C
		p->next = addTwoNumbers(l1->next,l2->next);		
		/* �Q�λ��j��k�I�s�ۤv�A�H���ӳ]�w p �᭱�`�I����ƭȤj�p�C
 		��Ƥ����޼ƬO�̭�l��J l1�Bl2 �᭱���`�I��}�C���L�ѩ�
 		���j�S�ʡA�U������ɪ���J�|�O l1�Bl2 �᭱�A�᭱���`�I��
 		�}�C����H�������A�]�� l1�Bl2 ���Ҧ����`�I���|�Q RUN ��A
		 �N�Y�|���C�Ӧ�ƪ���Ƭۥ[�B�Υu�^�Ǧh�X����ơC */
		if (a >= 10) 
			p->next = addTwoNumbers(p->next, new ListNode(1));	
		/* �A���Q�λ��j��k�I�s�ۤv�A�H��i�쪺���p�]�Ҽ{�i�h(�W��
 		���j�S���Ҽ{�i��)�C�Y��� LinkedList �����Ĥ@�Ӹ`�I��Ƭ�
 		�[�j�� 10�A�h�� p �᭱�`�I����ƭȤj�p�[�@�C�ӻ��j��k��
 		�@�����檺�ɶ��I�A�O�b�e�@�ӻ��j��k���AaddTwoNumbers
 		����Ӥ޼Ƴ����� NULL ���ɭԡC�̫�@������h�O�b���׭n
 		��X�Ӫ��e�@��(�Y l1�Bl2 ���Ĥ@�ӼƭȬۥ[�j�� 10 ����)�C */
		return p;
	}
};
