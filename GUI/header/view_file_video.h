#ifndef VIEW_FILE_VIDEO_H
#define VIEW_FILE_VIDEO_H

#include "view_file_multimedia.h"
#include "../../MODEL/header/file_video.h"

#include <QLineEdit>

class view_file_video : public virtual view_file_multimedia {
public:
    view_file_video(file_base* file, QWidget* parent=nullptr):view_file_multimedia(file, parent) {}

protected:
    virtual void edit() const;
    virtual void build_field();
    void edit_only_video() const;
    void build_filed_only_video();
private:
    QLineEdit* videoCodec;
    QLineEdit* width;
    QLineEdit* height;
};

#endif // VIEW_FILE_AUDIO_H
