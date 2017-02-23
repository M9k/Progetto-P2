#ifndef COMMON_FUNCTIONS_H
#define COMMON_FUNCTIONS_H

#include <QXmlStreamReader>
#include <string>

class unexpected_tag {};

void importTagXml(QXmlStreamReader&, const std::string, std::string&);

#endif
