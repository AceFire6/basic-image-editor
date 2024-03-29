#include <vector>
#include <string>

#ifndef _VOLIMAGE_H
#define _VOLIMAGE_H

namespace MLLJET001 {
    class VolImage {
    private: // private members
        int width, height, numImages; // width and height of image stack
        std::vector<unsigned char **> slices; // data for each slice, in order

    public: // public members
        VolImage(); // default constructor - define in .cpp
        ~VolImage(); // destructor - define in .cpp file

        // populate the object with images in stack and
        //set member variables define in .cpp
        bool readImages(std::string baseName);

        // compute difference map and write out; define in .cpp
        void diffmap(int sliceI, int sliceJ, std::string output_prefix);

        // extract slice sliceId and write to output - define in .cpp
        void extract(int sliceId, std::string output_prefix);

        // number of bytes uses to store image data bytes
        //and pointers (ignore vector<> container, dims etc)
        int volImageSize(); // define in .cpp

        int getImageCount();

        // Writes out bytes stored in 2D unsigned char array to a raw file.
        // Generates: <baseName>.dat and <baseName><sliceIndex>.raw
        // width and height are optional parameters that are only used for the '-g' flag output.
        void writeRawFile(std::string baseName, int sliceIndex, unsigned char **slice, int width=0, int height=0);

        // Extracts the same row from every image file and writes the result out with the
        // given output_prefix
        void rowExtract(int rowId, std::string output_prefix);
    };
}

#endif
