// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

/*
 * Copyright (C) 2009 RobotCub Consortium
 * Authors: Paul Fitzpatrick
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 *
 */

#include <stdio.h>

#include "yarp.h"
#include "yarpimpl.h"

    /**
     *
     * Read an integer from a connection.
     *
     */
YARP_DEFINE(int) yarpReaderExpectInt(yarpReaderPtr reader, int *data) {
    YARP_OK(reader);
    int x = YARP_READER(reader).expectInt();
    if (data!=NULL) {
        *data = x;
    }
    return YARP_READER(reader).isError()?-1:0;
}

    /**
     *
     * Read a floating point number from a connection.
     *
     */
YARP_DEFINE(int) yarpReaderExpectDouble(yarpReaderPtr reader, double *data) {
    YARP_OK(reader);
    double x = YARP_READER(reader).expectDouble();
    if (data!=NULL) {
        *data = x;
    }
    return YARP_READER(reader).isError()?-1:0;
}


    /**
     *
     * Read text from a connection.
     *
     */
YARP_DEFINE(int) yarpReaderExpectText(yarpReaderPtr reader, 
                                      yarpStringPtr str,
                                      char terminal) {
    YARP_OK(reader);
    YARP_STRING(str) = YARP_READER(reader).expectText(terminal);
    return YARP_READER(reader).isError()?-1:0;
}

    /**
     *
     * Read a block of data from a connection.
     *
     */
YARP_DEFINE(int) yarpReaderExpectBlock(yarpReaderPtr reader, 
                                       const char *data,
                                       int len) {
    YARP_OK(reader);
    return !YARP_READER(reader).expectBlock(data,len);
}


    /**
     *
     * Check if connection is text-mode
     *
     */
YARP_DEFINE(int) yarpReaderIsTextMode(yarpReaderPtr reader) {
    YARP_OK(reader);
    return YARP_READER(reader).isTextMode();
}


