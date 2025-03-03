DESCRIPTION = "Edge TPU runtime library (libedgetpu)"
HOMEPAGE = "https://github.com/google-coral/libedgetpu"
LICENSE = "Apache-2.0"

LIC_FILES_CHKSUM = "file://LICENSE;md5=86d3f3a95c324c9479bd8986968f4327"
PV = "grouper"

SRCREV_libedgetpu = "3164995622300286ef2bb14d7fdc2792dae045b7"
SRCREV_tensorflow = "d5b57ca93e506df258271ea00fc29cf98383a374"

SRC_URI = " \
    git://github.com/google-coral/libedgetpu.git;name=libedgetpu;branch="master";protocol=https \
    git://github.com/tensorflow/tensorflow.git;name=tensorflow;destsuffix=tensorflow;branch=r2.11;protocol=https \
    file://001-v2.11_libedgetpu_makefile.patch \
    file://001-v2.11_libedgetpu_allocated_buffer_header.patch \
"

S = "${WORKDIR}/git"
B = "${WORKDIR}/git/makefile_build"

DEPENDS = " \
    flatbuffers-native \
    vim-native \
    flatbuffers \
    abseil-cpp \
    libusb1 \
"

RDEPENDS:${PN} += " \
    flatbuffers \
    abseil-cpp \
    libusb1 \
"

EXTRA_OEMAKE = " libedgetpu"

do_configure:prepend () {
    export TFROOT=${WORKDIR}/tensorflow
}

do_compile:prepend() {
    export TFROOT=${WORKDIR}/tensorflow
}

BBCLASSEXTEND = "native nativesdk"
