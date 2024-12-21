//
// Created by LZ on 24-8-21.
//

#include "Dialog.h"

Dialog::Dialog(Line* currLine,QWidget *parent): QDialog(parent) {
            // 设置弹窗标题
            setWindowTitle("编辑活动时长");

            QSpinBox* spinBox = new QSpinBox(this);
            spinBox->setRange(1, 1000);  // 设置数字范围
            spinBox->setValue(1);  // 默认值

            // 创建 "确定" 和 "取消" 按钮
            QPushButton* okButton = new QPushButton("确定", this);
            QPushButton* cancelButton = new QPushButton("取消", this);

            // 布局设置
            QVBoxLayout* layout = new QVBoxLayout(this);
            layout->addWidget(spinBox);

            QHBoxLayout* buttonLayout = new QHBoxLayout();
            buttonLayout->addWidget(okButton);
            buttonLayout->addWidget(cancelButton);
            layout->addLayout(buttonLayout);

            // 连接按钮的信号槽
            connect(okButton, &QPushButton::clicked, this, [this, spinBox,currLine]() {
                // 获取输入值
                int value = spinBox->value();
                currLine->setlength(value);
                accept();  // 关闭对话框
            });
            connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);

}