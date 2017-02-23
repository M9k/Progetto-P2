#ifndef VIEW_FILE_AUDIOVIDEO_H
#define VIEW_FILE_AUDIOVIDEO_H

#include "view_file_audio.h"
#include "view_file_video.h"
#include "../../MODEL/header/file_audiovideo.h"

#include <QLineEdit>

class view_file_audiovideo : public view_file_audio, public view_file_video {
public:
    view_file_audiovideo(file_base* file, QWidget* parent=nullptr):
        view_file_multimedia(file, parent), view_file_audio(file), view_file_video(file) {}

protected:
    virtual void edit() const;
    virtual void build_field();
private:
    QLineEdit* containerFormat;
};

#endif // VIEW_FILE_AUDIOVIDEO_H
