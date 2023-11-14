#ifndef LINK_LIST_CPP
#define LINK_LIST_CPP
#include <iostream>
#include <string>
#include <iomanip>
#include "congviec.cpp"
using namespace std;

class node
{
private:
    CongViec cv;
    node *next;

public:
    node(CongViec cv, node *next) // ham tao gtri bd 1 nut của ds lk
    {
        this->cv = cv;
        this->next = next;
    }
    node *getNext() // lấy ra con trỏ (kdl *)
    {
        return next;
    }
    void setNext(node *p) // truyền gtri cho con trỏ next của ds
    {
        this->next = p;
    }
    CongViec getCongViec() // lấy ra cv
    {
        return cv;
    }
    void setCongViec(CongViec x) // truyền gtri cho cv x
    {
        this->cv = x;
    }
};

class list
{
private:
    node *head;
    int n; // đếm số công việc trong 1 list

public:
    list()
    {
        head = NULL;
        n = 0;
    }
    bool empty()
    {
        return n == 0; // ktra ds cv rỗng, nếu ko có ptu trả về n==0
    }
    // 2. ham in các cv trong ds lk: viết cho ý 2.
    void in()
    {
        node *temp = head;   // bd con trỏ temp trỏ đến đầu ds
        while (temp != NULL) // nếu temp chưa về cuối ds
        {
            cout << temp->getCongViec() << endl; // in ra lần lượt các gtri cv trong nút temp(lưu ý cv bên trên ta để private nên ở dưới khi muốn sd ta phải lấy cv=hàm get)
            temp = temp->getNext();              // cho con trỏ temp trỏ đến nút tiếp theo(tương tự ta ko trỏ đến next trực tiếp đc mà dùng hàm getNext() )
        }
    }
    // 1. ham chen 1 nut vao ds lk: viết cho ý 1
    void insert(CongViec x)
    {
        if (head == NULL) // chua co nut nao
        {
            head = new node(x, NULL); // gán gtri cho hàm tạo bd(tạo ra 1 nút :có gtri x, con trỏ next lúc này là NULL), sau đó gán lại vào head (nút đầu ds)
        }
        else
        {
            node *temp = head;              // bắt đầu từ đầu ds
            while (temp->getNext() != NULL) // nếu temp==NULL thì dừng (lúc này temp đã ở cuối ds)
            {
                temp = temp->getNext(); // duyệt cho đến cuối ds
            }

            node *p = new node(x, NULL); // tạo ra 1 nút p
            temp->setNext(p);            //  cho con trỏ sau của temp trỏ đến p => p dc thêm vào cuối ds(sau ptu cuối cùng temp)
        }
        // sắp xêp theo giờ tăng dần của cv: viết cho ý 1.
        node *p = head;
        node *q;
        CongViec temp;
        while (p != NULL) // nếu con trỏ đầu tiên của ds ko rỗng
        {
            q = p->getNext(); // con trỏ q =p+1 (duyệt sau con trỏ p 1 nút)
            while (q != NULL) // nếu con nút thứ 2 của ds cx ko rỗng (p!=null)
            {
                if (p->getCongViec().getGio() > q->getCongViec().getGio()) // nếu dtb của nút trc <nút sau => ta đổi vị trí 2 nút này lại
                {
                    // Đổi chỗ hai node
                    temp = q->getCongViec(); // gán tạm gtri temp ở nút p vào biến sinhvien temp
                    q->setCongViec(p->getCongViec());
                    p->setCongViec(temp); // gán gtri p(lúc này lưu tạm ở temp cho nút p)
                }
                q = q->getNext(); // lại dịch p sang nút tiếp theo
            }
            p = p->getNext(); // dịch p sang nút tiếp theo
        }
    }
    // 3. in theo tinh chat cv  :viết cho ý 3.
    void inCongViec_theoTinhChat(string TinhChat)
    {
        node *temp = head;   // bd con trỏ temp trỏ đến đầu ds
        while (temp != NULL) // nếu temp chưa về cuối ds
        {
            if (temp->getCongViec().getTinhChat() == TinhChat)
            {
                cout << temp->getCongViec();
            }
            temp = temp->getNext();
        }
    }
    // 4. hàm tìm cv theo tên ( dùng cho ý xóa hay điều chỉnh lịch công tác )
    void xoaCongViec_theoTen(string ten)
    {
        node *temp = head;
        node *prev = NULL;

        while (temp != NULL)
        {
            if (temp->getCongViec().getTen() == ten)
            {
                if (prev == NULL)
                {
                    // Nếu nút cần xóa là nút đầu danh sách
                    head = temp->getNext();
                }
                else
                {
                    // Nếu nút cần xóa không phải là nút đầu danh sách
                    prev->setNext(temp->getNext());
                }

                // Xóa nút và giải phóng bộ nhớ
                delete temp;
                cout << "Cong viec da duoc xoa.\n";
                return;
            }

            // Di chuyển đến nút tiếp theo
            prev = temp;
            temp = temp->getNext();
        }

        // Nếu không tìm thấy công việc có tên trùng khớp
        cout << "Khong tim thay cong viec co ten '" << ten << "'.\n";
    }
};

#endif