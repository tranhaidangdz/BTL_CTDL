#ifndef LINK_LIST_
#define LINK_LIST_

#include <iostream>
#include "congviec.h"

struct node // node trong dslk mình viết thường, còn trong cây viết hoa chữ N: Node
{
    CongViec data; // tạo 1 ds lk đơn chứa gtri = dữ liệu 1 công việc
    node *next;    // con trỏ next để trỏ đến nút sau nó
};
void init(node *&head) // 1/ khởi tạo nút đầu của ds: cho nút head trỏ đến NULL. do con trỏ head là "biến cục bộ của hàm", khi hàm kết thúc nó sẽ giải phóng bộ nhớ của con trỏ head luôn
// ta thêm *&head để truyền dịa chỉ con trỏ, khi hàm kết thúc nó vẫn duy trì gtri cho các hàm khác sd
{
    head = NULL;
}

// 2.tạo 1 nút mới:
node *creatNode(CongViec x)
{
    node *p = new node; // tạp 1 nút để chứa gtri và con trỏ
    p->data = x;        // cho gtri của nút = gtri x truyền vào
    p->next = NULL;     // nút sau của nó =null(cuối ds)
    return p;
}

// 3. kiem tra ds rỗng:
bool KtraRong(node *p)
{
    return p == NULL; // so sánh nếu nút p rỗng thì trả về rỗng
}

// 4.trả về kích thước ds:
int size(node *p)
{
    int count = 0;
    while (p != NULL)
    {
        ++count;
        p = p->next; // cho nút p trỏ dần đến nút sau nó
    }
    return count;
}

// 5. thêm nút vào đầu ds:
void addFisrt(node *&head, CongViec x)
{
    node *p = creatNode(x); // tạo 1 nút mới
                            // muốn nó thành ptu đầu ds ta cho con trỏ next của nó trỏ đến đầu ds, con trỏ head đầu ds sẽ trỏ đến nó
    p->next = head;         // cho con trỏ sau của nút sau
    head = p;
}
// 6.in ra danh sach công việc trong ngày = in ra 1 nút của cây nhị phân:
void output(node *head)
{
    node *p = head;   // bd con trỏ p trỏ đến nút đầu ds, sau đó duyệt hết ds
    while (p != NULL) // nếu nó chưa về cuối ds thì tiếp tục duyệt
    {
        // cout << p->hv << "\t"; // in ra từng gtri của nút p
        cout << p->data << "\t";
        p = p->next; // cho con trỏ next của nút p duyệt đến nút kế tiếp <=.> i++
    }
}

// 7.thêm ptu vào cuối ds:
/*
-ta cho next của nút cuối mới này trỏ đén NULL. còn next của nút cuối trc đó trỏ đến nút này
-NHƯNg : vấn đề là ta phải xác định dc nút cuối của ds là ở đâu
>> ta duyệt từ đầu-> cuối ds, khi ktra p->next == NULL thì đã tìm thấy nút cuối
*/
void addLast(node *&head, CongViec x)
{
    node *p = creatNode(x); // tao 1 nut
    if (head == NULL)
    {
        head = p; // nếu ds đang rỗng thì thêm ptu vào cuối cx chính là thêm ptu vào đầu ds
    }
    else
    {
        // xác định nút cuối cùng:
        node *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        // chèn vào cuối:
        last->next = p; // lúc này con trỏ của nút cuối trỏ đến p(giờ p mới là nút cuối)
    }
}

void deleteFirst(node *&head) // 8. thêm xóa ptu ta đều truyền vào con trỏ "Node *&head"
{
    // CHÚ Ý: NẾU DS RỖNG, thì khi ta cho con trỏ p(NULL) trỏ đến p->next(chưa có ptu nào thì ko trỏ đến ptu sau đc) thì nó bị lỗi "NULL pointer" => ta chỉ xóa dc khi trong ds có >=1 ptu
    if (head != NULL)
    {
        node *p = head; // ban đầu trỏ đến ptu đầu ds
        head = p->next; // cho con trỏ head(đánh dấu đầu ds), trỏ đén nút thứ 2
        p->next = NULL; // cho con trỏ nút đầu thành rỗng
        delete (p);     // xóa đi con trỏ nút đầu
    }
}
// 9. XÓA PTU chỉ định(gtri cụ thể) TRONG DS LK:
/*
VD ta có 3 ptu 7  8  6  9   4 ,ta muốn xóa đi ptu 8
>>ta xác định ptu trước nó và chính nó : số 7 và số 8
>> cho con trỏ của ptu trc nó(ptu prev) trỏ đến ptu sau nó(bỏ qua chính nó): cho prev trỏ đến số 6
>>cho con trỏ của số 8 trỏ đén NULL
>>xóa đi con trỏ của số 8
*/
void deleteNode(node *&head, CongViec v) // v: gtri ptu muốn xóa
{
    if (head != NULL) // nếu ds ko rỗng
    {
        node *p = head;    // con trỏ vị trí p bd ở đầu ds
        node *prev = NULL; //=> con trỏ trc nó đang trỏ vào vùng rỗng ngoài ds

        while (p != NULL && p->data.getGio() != v.getGio())
        {                // nếu chưa tìm thấy nút có gtri v
            prev = p;    // ta cho con trỏ trc p trỏ đến p
            p = p->next; // sau đó lùi p ra phía sau tìm gtri 2 tiếp
        }
        if (p != NULL)
        {
            if (prev == NULL) // nếu ds chỉ có 1 ptu
            {
                deleteFirst(head); // xóa ptu đó bằng hàm xóa ptu đầu tiên
            }
            else
            {
                prev->next = p->next; // cho ptu prev trỏ đến ptu sau ptu p(bỏ qua p)
                p->next = NULL;       // cho ptu p trỏ đến vùng null
                delete (p);           // xóa đi p
            }
        }
        else // nếu p==NULL: tức là duyệt duyệt hết ds(lúc này p là ptu cuối,nó trỏ đến NULL) rồi mà ko tìm thấy ptu cần xóa thì ta in ra tb
        {
            cout << "\nko tim thay ptu can xoa:" << endl;
        }
    }
}
// 10. XÓA TOÀN BỘ DS:
void clear(node *&head)
{
    while (head != NULL) // nếu chưa đến cuối ds thì tiếp tục xóa
    {
        deleteFirst(head); // xóa đi từng ptu trong ds
    }
}

#endif