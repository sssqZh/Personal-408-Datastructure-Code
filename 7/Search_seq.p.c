typedef struct {
    ElemType *elem;
    int TableLen;
}SSTable;

int Search_Seq(SSTable ST, ElemType key) {
    int i;
    ST.elem[0]=key   ; // 哨兵
    for(i=0;i<ST.TableLen&&ST.elem[i]!=key;++i);
    return i;
}