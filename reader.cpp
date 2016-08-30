#include <iostream>
#include <itkImageFileReader.h>
#include <itkImage.h>

#include <itkImageIOFactory.h>
#include <itkSCIFIOImageIOFactory.h>

int main(int argc, char* argv[])
{
  itk::MultiThreader::SetGlobalMaximumNumberOfThreads(1);
  ::itk::Object::GlobalWarningDisplayOn();
  itk::SCIFIOImageIOFactory::RegisterOneFactory();
  typedef itk::Image<unsigned char,2> ImageType;
  typedef itk::ImageFileReader<ImageType> ReaderType;
  ReaderType::Pointer reader = ReaderType::New();
  reader->SetFileName(argv[1]);
  reader->Update();

  ImageType::PointType origin = reader->GetOutput()->GetOrigin() ;

  ImageType::SizeType size = reader->GetOutput()->GetLargestPossibleRegion().GetSize();
  
  ImageType::DirectionType direction = reader->GetOutput()->GetDirection();

  ImageType::SpacingType spacing = reader->GetOutput()->GetSpacing();

  std::cout<<"origin:"<<origin<<std::endl;
  std::cout<<"spacing:"<<spacing<<std::endl;
  std::cout<<"direction:"<<direction<<std::endl;
  std::cout<<"size:"<<size<<std::endl;

  return 0;
}
