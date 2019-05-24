/*
  Written by John Michael Hayde and Timothy Quinton
*/
#include "image/Image.h"
#include "filter/SharpenFilter.h"
#include "filter/BlurFilter.h"
#include "filter/HFlipFilter.h"
#include "filter/VFlipFilter.h"
#include "filter/BinaryFilter.h"
#include "filter/SepiaFilter.h"
#include "filter/GrayscaleFilter.h"

int main(int argc, char* argv[]) {

  //checks for correct CL args
  if(argc != 2) {
    cout << "ERROR: this programs requires 2 command line arguments!" << endl;
    exit(0);
  }

  //opens input file
  ifstream in(argv[1]);

  //checks validity of input file
  if(!in) {
    cout << "ERROR: could not open input file!" << endl;
    exit(0);
  }

  //makes image to construct copies off of
  Image original_img(in);


/*
  *************************************************
   functionality of each single filter code block
  *************************************************

  //opens output file
  ofstream out_file ("output_image");

  //creates new image based off original_img
  Image out_image (original_img);

  //makes instance of desired filter and applies to image
  SharpenFilter sharpen;
  sharpen.apply(out_image);

  //makes p3 and writes image to output file
  out_image.make_p3();
  out_image.write_to(out_file);

  //closes output file
  out_file.close();
*/


  //**********************************************
  //      makes sharpened image
  //**********************************************
  ofstream out_sharpen ("sharpen_100.ppm");

  Image out_img_sharpen(original_img);

  SharpenFilter sharpen;
  sharpen.apply(out_img_sharpen);

  out_img_sharpen.make_p3();
  out_img_sharpen.write_to(out_sharpen);

  out_sharpen.close();


  //**********************************************
  //      makes blurred image
  //**********************************************
  ofstream out_blur ("blur_100.ppm");

  Image out_image_blur(original_img);

  BlurFilter blur;
  blur.apply(out_image_blur);

  out_image_blur.make_p3();
  out_image_blur.write_to(out_blur);

  out_blur.close();


  //********************************************
  //      makes hflip image
  //********************************************
  ofstream out_hflip ("horizontal_100.ppm");

  Image out_image_hflip(original_img);

  HFlipFilter hflip;
  hflip.apply(out_image_hflip);

  out_image_hflip.make_p3();
  out_image_hflip.write_to(out_hflip);

  out_hflip.close();


  //********************************************
  //     makes vflip filter
  //********************************************
  ofstream out_vflip ("vertical_100.ppm");

  Image out_image_vflip(original_img);

  VFlipFilter vflip;
  vflip.apply(out_image_vflip);

  out_image_vflip.make_p3();
  out_image_vflip.write_to(out_vflip);

  out_vflip.close();


  //********************************************
  //     makes binary filter
  //********************************************
  ofstream out_binary ("binary_100.ppm");

  Image out_image_binary(original_img);

  BinaryFilter binary;
  binary.apply(out_image_binary);

  out_image_binary.make_p3();
  out_image_binary.write_to(out_binary);

  out_binary.close();


  //********************************************
  //     makes sepia filter
  //********************************************
  ofstream out_sepia ("sepia_100.ppm");

  Image out_image_sepia(original_img);

  SepiaFilter sepia;
  sepia.apply(out_image_sepia);

  out_image_sepia.make_p3();
  out_image_sepia.write_to(out_sepia);

  out_sepia.close();


  //********************************************
  //     makes grayscale filter
  //********************************************
  ofstream out_gray ("grayscale_100.ppm");

  Image out_image_gray(original_img);

  GrayscaleFilter gray;
  gray.apply(out_image_gray);

  out_image_gray.make_p3();
  out_image_gray.write_to(out_gray);

  out_gray.close();


  /*
    *************************************************
     functionality of each multi filter code block
    *************************************************

    //opens output file
    ofstream out_file ("image.ppm");

    //makes new image based off original_img
    Image out_image(original_img);

    //makes instances of desired filters
    SharpenFilter sharpen;
    BinaryFilter binary;
    HFlipFilter hflip;

    //makes a vector of Filter*'s containing desired filters
    vector<Filter*> img_vec1 = {
      &mult1_sharpen, &mult1_bin, &mult1_hflip
    };

    //loops through the vector and applies each filter to the image
    for(Filter* filter : img_vec1) {
      filter->apply(out_image_mult1);
    }

    //makes out_image p3 and writes to output file
    out_image.make_p3();
    out_image.write_to(out_file);

    //closes output file
    out_file.close();

  */


  //************************************************
  // makes multi filter 1 (shapren, binary, hflip)
  //************************************************
  ofstream out_mult1 ("shar_bin_hf_100.ppm");

  Image out_image_mult1(original_img);

  SharpenFilter mult1_sharpen;
  BinaryFilter mult1_bin;
  HFlipFilter mult1_hflip;

  vector<Filter*> img_vec1 = {
    &mult1_sharpen, &mult1_bin, &mult1_hflip
  };

  for(Filter* filter : img_vec1) {
    filter->apply(out_image_mult1);
  }

  out_image_mult1.make_p3();
  out_image_mult1.write_to(out_mult1);

  out_mult1.close();


  //***********************************************
  // makes multi filter 2 (shapren, sepia, vflip)
  //***********************************************
  ofstream out_mult2 ("shar_sep_vf_100.ppm");

  Image out_image_mult2(original_img);

  SharpenFilter mult2_sharpen;
  SepiaFilter mult2_sep;
  VFlipFilter mult2_vflip;

  vector<Filter*> img_vec2 = {
    &mult2_sharpen, &mult2_sep, &mult2_vflip
  };

  for(Filter* filter : img_vec2) {
    filter->apply(out_image_mult2);
  }

  out_image_mult2.make_p3();
  out_image_mult2.write_to(out_mult2);

  out_mult2.close();


  //***************************************************
  // makes multi filter 3 (sharpen, grayscale, hflip)
  //***************************************************
  ofstream out_mult3 ("shar_gs_hf_100.ppm");

  Image out_image_mult3(original_img);

  SharpenFilter mult3_sharpen;
  GrayscaleFilter mult3_gray;
  HFlipFilter mult3_hflip;

  vector<Filter*> img_vec3 = {
    &mult3_sharpen, &mult3_gray, &mult3_hflip
  };

  for(Filter* filter : img_vec3) {
    filter->apply(out_image_mult3);
  }

  out_image_mult3.make_p3();
  out_image_mult3.write_to(out_mult3);

  out_mult3.close();


  //************************************************
  // makes multi filter 4 (blur, grayscale, vflip)
  //************************************************
  ofstream out_mult4 ("blur_gs_vf_100.ppm");

  Image out_image_mult4(original_img);

  BlurFilter mult4_blur;
  GrayscaleFilter mult4_gray;
  VFlipFilter mult4_vflip;

  vector<Filter*> img_vec4 = {
    &mult4_blur, &mult4_gray, &mult4_vflip
  };

  for(Filter* filter : img_vec4) {
    filter->apply(out_image_mult4);
  }

  out_image_mult4.make_p3();
  out_image_mult4.write_to(out_mult4);

  out_mult4.close();


  //********************************************
  // makes multi filter 5 (blur, binry, hflip)
  //********************************************
  ofstream out_mult5 ("blur_bin_hf_100.ppm");

  Image out_image_mult5(original_img);

  BlurFilter mult5_blur;
  BinaryFilter mult5_bin;
  HFlipFilter mult5_hflip;

  vector<Filter*> img_vec5 = {
    &mult5_blur, &mult5_bin, &mult5_hflip
  };

  for(Filter* filter : img_vec5) {
    filter->apply(out_image_mult5);
  }

  out_image_mult5.make_p3();
  out_image_mult5.write_to(out_mult5);

  out_mult5.close();


  //********************************************
  // makes multi filter 6 (blur, sepia, vflip)
  //********************************************
  ofstream out_mult6 ("blur_sep_vf_100.ppm");

  Image out_image_mult6(original_img);

  BlurFilter mult6_blur;
  SepiaFilter mult6_sep;
  VFlipFilter mult6_vflip;

  vector<Filter*> img_vec6 = {
    &mult6_blur, &mult6_sep, &mult6_vflip
  };

  for(Filter* filter : img_vec6) {
    filter->apply(out_image_mult6);
  }

  out_image_mult6.make_p3();
  out_image_mult6.write_to(out_mult6);

  out_mult6.close();


  //************************************************************
  // makes multi filter 7 (sharpen twice, sepia, hflip, vflip)
  //************************************************************
  ofstream out_mult7 ("stud_creation_100.ppm");

  Image out_image_mult7(original_img);

  SharpenFilter mult7_sharpen;
  SharpenFilter mult7_sharpen2;
  SepiaFilter mult7_sep;
  HFlipFilter mult7_hflip;
  VFlipFilter mult7_vflip;

  vector<Filter*> img_vec7 = {
    &mult7_sharpen, &mult7_sharpen2, &mult7_sep, &mult7_hflip, &mult7_vflip
  };

  for(Filter* filter : img_vec7) {
    filter->apply(out_image_mult7);
  };

  out_image_mult7.make_p3();
  out_image_mult7.write_to(out_mult7);

  out_mult7.close();


  //closes input file
  in.close();


  return 0;
}
