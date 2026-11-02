#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ResizeTable_bt_clicked()
{
    //Lấy giá trị n (số tiến trình) và m (số loại tài nguyên) từ QSpinBox.
    int n = ui->spinN->value();
    int m = ui->spinM->value();

    // Kiểm tra an toàn: nếu n hoặc m bằng 0 thì không làm gì cả.
    if (n <= 0 || m <= 0) {
        return;
    }

    //Cấu hình kích thước cho các ma trận n hàng x m cột (Allocation, Max, Request, Need)
    //Bảng Allocation
    ui->Allocation_table->setRowCount(n);
    ui->Allocation_table->setColumnCount(m);

    //Bảng Max
    ui->Max_table->setRowCount(n);
    ui->Max_table->setColumnCount(m);

    //Bảng Request
    ui->Request_table->setRowCount(n);
    ui->Request_table->setColumnCount(m);

    //Bảng Need
    ui->Need_table->setRowCount(n);
    ui->Need_table->setColumnCount(m);

    //Cấu hình cho vector Available (có kích thước 1 hàng x m cột)
    ui->Available_table->setRowCount(1);
    ui->Available_table->setColumnCount(m);

    //Đặt tên tiêu đề các cột (R0, R1... hoặc Resource 0, 1...) cho dễ nhìn
    QStringList resourceHeaders;
    for (int j = 0; j < m; ++j) {
        resourceHeaders << "R" + QString::number(j);
    }

    QStringList processHeaders;
    for (int i = 0; i < n; ++i) {
        processHeaders << "P" + QString::number(i);
    }

    //Áp dụng tiêu đề cột và hàng cho các bảng n x m
    ui->Allocation_table->setHorizontalHeaderLabels(resourceHeaders);
    ui->Allocation_table->setVerticalHeaderLabels(processHeaders);

    ui->Max_table->setHorizontalHeaderLabels(resourceHeaders);
    ui->Max_table->setVerticalHeaderLabels(processHeaders);

    ui->Request_table->setHorizontalHeaderLabels(resourceHeaders);
    ui->Request_table->setVerticalHeaderLabels(processHeaders);

    ui->Need_table->setHorizontalHeaderLabels(resourceHeaders);
    ui->Need_table->setVerticalHeaderLabels(processHeaders);

    //Bảng Available chỉ cần 1 hàng
    ui->Available_table->setHorizontalHeaderLabels(resourceHeaders);
    ui->Available_table->setVerticalHeaderLabels(QStringList() << "Avail");

    //In thông báo xác nhận ra khung log để kiểm tra
    ui->txtLog->append("Đã tạo/cập nhật bảng thành công: " + QString::number(n) + " tiến trình, " + QString::number(m) + " loại tài nguyên.");
}

