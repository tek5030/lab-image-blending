from conans import ConanFile, CMake

class SolutionTransformations(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = "opencv/4.5.5"
    generators = "cmake_find_package", "virtualrunenv"
    default_options = {
        "opencv:dnn": False,
        "opencv:nonfree": True,
        "opencv:with_ffmpeg": False
    }

    def configure(self):
        if self.settings.os == "Linux":
            self.options["opencv"].with_v4l = True
