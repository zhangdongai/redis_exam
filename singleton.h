#pragma once

#define SINGLETION_DECLARE(CLASS)        \
public:                                  \
    static CLASS* instance() {           \
        static CLASS object;             \
        return &object;                  \
    }                                    \
private:                                 \
    CLASS();                             \
    CLASS(const CLASS&);                 \
    CLASS& operator = (const CLASS&);    \
