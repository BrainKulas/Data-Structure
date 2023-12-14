/*=============================
 * ���Ա���˳��洢�ṹ��˳�����
 *
 * �����㷨: 2.3��2.4��2.5��2.6
 =============================*/

#include "SqList.h"

/*
 * ���������������� �㷨2.3 ����������������
 *
 * ��ʼ��
 *
 * ��ʼ���ɹ��򷵻�OK�����򷵻�ERROR��
 */
Status InitList(SqList* L) {
    // ����ָ���������ڴ棬�������ʧ�ܣ��򷵻�NULL
    (*L).elem = (ElemType*) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if((*L).elem == NULL) {
        // �洢�ڴ�ʧ��
        exit(OVERFLOW);
    }
    
    (*L).length = 0;                    // ��ʼ��˳�������Ϊ0
    (*L).listsize = LIST_INIT_SIZE;     // ˳�����ʼ�ڴ������
    
    return OK;                          // ��ʼ���ɹ�
}

/*
 * ����
 *
 * ����˳�����������ЧԪ�ص�������
 */
int ListLength(SqList L) {
    return L.length;
}

/*
 * ȡֵ
 *
 * ��ȡ˳����е�i��Ԫ�أ�����洢��e�С�
 * ��������ҵ�������OK�����򣬷���ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ���������ⲻ���ϱ����ͨ��Լ����
 * ͨ����i�ĺ���Ӧ��ָ����������0��ʼ������
 */
Status GetElem(SqList L, int i, ElemType* e) {
    // ��Ϊi�ĺ�����λ�ã�������Ϸ���Χ�ǣ�[1, length]
    if(i < 1 || i > L.length) {
        return ERROR;                    //iֵ���Ϸ�
    }
    
    *e = L.elem[i - 1];
    
    return OK;
}

/*
 * ���������������� �㷨2.4 ����������������
 *
 * ����
 *
 * ��˳�����i��λ���ϲ���e������ɹ��򷵻�OK�����򷵻�ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ����
 */
Status ListInsert(SqList* L, int i, ElemType e) {
    ElemType* newbase;
    ElemType* p, * q;
    
    // ȷ��˳����ṹ����
    if(L == NULL || (*L).elem == NULL) {
        return ERROR;
    }
    
    // iֵԽ��
    if(i < 1 || i > (*L).length + 1) {
        return ERROR;
    }
    
    // ���洢�ռ��������������¿ռ�
    if((*L).length >= (*L).listsize) {
        // �������пռ�����
        newbase = (ElemType*) realloc((*L).elem, ((*L).listsize + LISTINCREMENT) * sizeof(ElemType));
        if(newbase == NULL) {
            // �洢�ڴ�ʧ��
            exit(OVERFLOW);
        }
        
        // �»�ַ
        (*L).elem = newbase;
        // ��Ĵ洢�ռ�
        (*L).listsize += LISTINCREMENT;
    }
    
    // qΪ����λ��
    q = &(*L).elem[i - 1];
    
    // 1.����Ԫ�أ��ڳ�λ��
    for(p = &(*L).elem[(*L).length - 1]; p >= q; --p) {
        *(p + 1) = *p;
    }
    
    // 2.����e
    *q = e;
    
    // 3.������1
    (*L).length++;
    
    return OK;
}

/*
 * ���������������� �㷨2.5 ����������������
 *
 * ɾ��
 *
 * ɾ��˳�����i��λ���ϵ�Ԫ�أ�������ɾ��Ԫ�ش洢��e�С�
 * ɾ���ɹ��򷵻�OK�����򷵻�ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ����
 */
Status ListDelete(SqList* L, int i, ElemType* e) {
    ElemType* p, * q;
    
    // ȷ��˳����ṹ����
    if(L == NULL || (*L).elem == NULL) {
        return ERROR;
    }
    
    // iֵԽ��
    if(i < 1 || i > (*L).length) {
        return ERROR;
    }
    
    // pΪ��ɾ��Ԫ�ص�λ��
    p = &(*L).elem[i - 1];
    
    // 1.��ȡ��ɾ��Ԫ��
    *e = *p;
    
    // ��βԪ��λ��
    q = (*L).elem + (*L).length - 1;
    
    // 2.����Ԫ�أ���ɾ��Ԫ�ص�λ���ϻ�����Ԫ�ؽ���
    for(++p; p <= q; ++p) {
        *(p - 1) = *p;
    }
    
    // 3.������1
    (*L).length--;
    
    return OK;
}

/*
 * ����
 *
 * ��visit��������˳���L
 */
void ListTraverse(SqList L, void(Visit)(ElemType)) {
    int i;
    
    for(i = 0; i < L.length; i++) {
        Visit(L.elem[i]);
    }
    
    printf("\n");
}