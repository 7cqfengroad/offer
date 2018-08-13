#include <iostream>
#include <vector>

using namespace std;

struct RandomListNode{
	int label;
	struct RandomListNode *next, *random;
};


RandomListNode* Clone(RandomListNode* pHead)
{
	if(pHead == NULL)
	{
		return NULL;
	}
	RandomListNode *ph = pHead, *pmid, *p;
	while(ph != NULL)
	{
		p = new RandomListNode;
		pmid = ph->next;
		p->label = ph->label;
		ph->next = p;
		p->next = pmid;
		ph = ph->next->next;
	}
	
	// 复制 random 部分
	p = pHead;
	while(p != NULL)
	{
		cout << "copy" << endl;
		pmid = p->next;
		pmid->random = p->random->next;
		p = pmid->next;
	}		

	// 分离复制的链表
	p = pHead;
	RandomListNode *pmidh = pHead->next;
	while(p != NULL)
	{
		pmid = p->next;
		cout << "fenli" << endl;
		cout << "pmid->label: " << pmid->label << endl;
		p->next = pmid->next;
		p = p->next;
		if(p != NULL)
		{
			pmid->next = p->next;	
		}
	}
	//pmid->next = NULL;	
	
	return pmidh;
}

void show_next(RandomListNode *pph)
{
	RandomListNode *pp = pph;
	while(pp != NULL)
	{
		cout << pp->label << " ";
		pp = pp->next;
	}
	cout << endl;
}

void show_random(RandomListNode *pph)
{
	RandomListNode *pp = pph->random;
	for(int i = 0; i < 10; i++)
	{
		cout << pp->label << " ";
		pp = pp->random;
	}
	cout << endl;
}


int main()
{
	RandomListNode *pph = new RandomListNode;
	pph->label = 0;
	pph->next = NULL;
	RandomListNode *pp = pph;
	for(int i = 1; i < 10; i++)
	{
		RandomListNode *ppn = new RandomListNode;
		ppn->label = i;
		ppn->next = NULL;
		pp->next = ppn;
		pp = pp->next;	
	}	
	show_next(pph);
	int ran[10] = {2, 6, 8, 9, 4, 3, 5, 1, 7, 0};
	pp = pph;
	int ri= 0;
	while(pp != NULL && ri < 10)
	{
		cout << "ri: " << ri << endl;
		RandomListNode *ppm = pph;
		for(int rj = 0; rj < ran[ri]; rj++)
		{
			ppm = ppm->next;
		}
		pp->random = ppm;
		pp = pp->next;
		ri++;
	}	
	show_random(pph);
	RandomListNode *a = Clone(pph);
	cout << "after clone" << endl;
	show_next(a);
}
