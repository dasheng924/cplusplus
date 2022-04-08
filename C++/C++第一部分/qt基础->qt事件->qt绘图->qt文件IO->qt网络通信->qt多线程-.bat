qt基础->qt事件->qt绘图->qt文件IO->qt网络通信->qt多线程->qt数据库操作


/Users/sunguosheng/Code/Qt/build-HelloQt-Desktop_Qt_5_9_9_clang_64bit-Debug/moc_mainwindow.cpp

观察者模式

    QMessageBox pm1;
    pm1.setText("text has beeen changed");
    pm1.setInformativeText("Do you want to save?");
    pm1.setDetailedText("AAAAAAAA\nBBBBBBBB\nCCCCCC\nDDDDDDD");
    pm1.setStandardButtons(QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
    pm1.setIcon(QMessageBox::Question);
    pm1.setWindowModality(Qt::NonModal);//设置为非模态
    QObject::connect(pd,&QPushButton::clicked,&pm1,&QMessageBox::show);
    QObject::connect(pd1,&QPushButton::clicked,&pm1,&QMessageBox::exec);
