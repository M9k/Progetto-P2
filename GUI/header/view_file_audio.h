#ifndef VIEW_FILE_AUDIO_H
#define VIEW_FILE_AUDIO_H

#include "view_file_multimedia.h"
#include "../../MODEL/header/file_audio.h"

#include <QLineEdit>

class view_file_audio : public virtual view_file_multimedia {
public:
    view_file_audio(file_base* file, QWidget* parent=nullptr):view_file_multimedia(file, parent) {}

protected:
    virtual void edit() const;
    virtual void build_field();
private:
    QLineEdit* audioCodec;
    QLineEdit* campionamento;
};

#endif // VIEW_FILE_AUDIO_H
