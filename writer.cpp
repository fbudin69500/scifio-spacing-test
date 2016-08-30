#include <iostream>
#include <itkImageFileWriter.h>
#include <itkImage.h>

#include <itkImageIOFactory.h>
//#include <itkMetaImageIOFactory.h>
//#include <itkNrrdImageIOFactory.h>
#include <itkSCIFIOImageIOFactory.h>

int main(int argc, char* argv[])
{
  itk::MultiThreader::SetGlobalMaximumNumberOfThreads(1);
  itk::SCIFIOImageIOFactory::RegisterOneFactory();
  typedef itk::Image<unsigned char,2> ImageType;
  ImageType::Pointer image = ImageType::New();
  ImageType::PointType origin ;
  origin[0] = 1.2;
  origin[1] = 1.3;
  //origin[2] = 2.5;
  image->SetOrigin(origin);

  ImageType::SizeType size ;
  size[0]=11;
  size[1] = 23;
  //size[2] = 34;
  image->SetRegions(size);

  ImageType::DirectionType direction;
  direction.SetIdentity();
  direction[0][0] = 0;
  direction[1][0] = -1;
  direction[0][1] = 1;
  direction[1][1] = 0;
  image->SetDirection(direction);

  ImageType::SpacingType spacing;
  spacing[0]=.3;
  spacing[1] = .67;
  //spacing[2] = 1.4;
  image->SetSpacing(spacing);

  image->Allocate();

  image->SetRegions(size);
  image->FillBuffer(0);
  typedef itk::ImageFileWriter<ImageType> WriterType;
  WriterType::Pointer writer = WriterType::New();
  writer->DebugOn();
  writer->SetFileName(argv[1]);
  writer->SetInput(image);
  writer->Update();

  return 0;
}
