#include "RenamerPlaceholders.h"
#include "ui_RenamerPlaceholders.h"

RenamerPlaceholders::RenamerPlaceholders(QWidget* parent) : QWidget(parent), ui(new Ui::RenamerPlaceholders)
{
    ui->setupUi(this);
    setType(RenameType::Movies);
}

RenamerPlaceholders::~RenamerPlaceholders()
{
    delete ui;
}

void RenamerPlaceholders::setType(RenameType renameType)
{
    using Type = RenameType;

    for (const auto label : ui->groupBox->findChildren<QLabel*>()) {
        const auto itemTypes = label->property("itemTypes").toStringList();
        if (itemTypes.isEmpty()) {
            continue;
        }
        label->setVisible((renameType == Type::Movies && itemTypes.contains("movie"))
                          || (renameType == Type::TvShows && itemTypes.contains("tvshow"))
                          || (renameType == Type::Concerts && itemTypes.contains("concert")));
    }
}
