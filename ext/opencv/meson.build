gstopencv_sources = [
  'gstcvdilate.cpp',
  'gstcvdilateerode.cpp',
  'gstcvequalizehist.cpp',
  'gstcverode.cpp',
  'gstcvlaplace.cpp',
  'gstcvsobel.cpp',
  'gstedgedetect.cpp',
  'gstmotioncells.cpp',
  'gstopencv.cpp',
  'gstretinex.cpp',
  'gstskindetect.cpp',
  'gsttextoverlay.cpp',
  'MotionCells.cpp',
  'motioncells_wrapper.cpp',
  'gstcvtracker.cpp'
]
#  'gstcvsmooth.cpp',
#  'gstfaceblur.cpp',
#  'gstfacedetect.cpp',
#  'gstdewarp.cpp',
#  'gstgrabcut.cpp',
#  'gstdisparity.cpp',
#  'gstsegmentation.cpp',
#  'gsttemplatematch.cpp',
#  'gsthanddetect.cpp',

libopencv2_headers = [
  'opencv2/core/core_c.h',
  'opencv2/core/version.hpp',
  'opencv2/highgui/highgui_c.h',
  'opencv2/imgproc/imgproc.hpp',
  'opencv2/imgproc/imgproc_c.h',
  'opencv2/objdetect/objdetect.hpp',
  'opencv2/video/background_segm.hpp',
  'opencv2/tracking.hpp'
]

libopencv4_headers = [
  'opencv2/video/background_segm.hpp',
  'opencv4/opencv2/calib3d.hpp',
  'opencv4/opencv2/core.hpp',
  'opencv4/opencv2/imgproc.hpp',
  'opencv4/opencv2/objdetect.hpp',
  'opencv4/opencv2/opencv.hpp',
  'opencv4/opencv2/video.hpp',
  'opencv4/opencv2/tracking.hpp',
]

gstopencv_cargs = ['-DGST_HAAR_CASCADES_DIR="@0@"']

opencv_dep = dependency('opencv', version : ['>= 2.3.0', '< 3.5.0'], required : false)
opencv_found = opencv_dep.found()

if opencv_found
  foreach h : libopencv2_headers
    if not cxx.has_header(h)
      message('Needed header "' + h + '" not found')
      opencv_found = false
    endif
  endforeach
endif

if not opencv_found
  opencv_dep = dependency('opencv4', version : ['>= 4.0.0', '< 4.6.0'], required : false)
  opencv_found = opencv_dep.found()
  if opencv_found
    foreach h : libopencv4_headers
      if not cxx.has_header(h)
        message('Needed header "' + h + '" not found')
        opencv_found = false
      endif
    endforeach
  endif
endif
   
if opencv_found
  opencv_prefix = opencv_dep.get_pkgconfig_variable('prefix')
  gstopencv_cargs += ['-DOPENCV_PREFIX="' + opencv_prefix + '"']

  # Check the data dir used by opencv for its xml data files
  # Use prefix from pkg-config to be compatible with cross-compilation
  r = run_command('test', '-d', opencv_prefix + '/share/opencv')
  if r.returncode() == 0
    gstopencv_cargs += '-DOPENCV_PATH_NAME="opencv"'
  else
    r = run_command('test', '-d', opencv_prefix + '/share/OpenCV')
    if r.returncode() == 0
      gstopencv_cargs += '-DOPENCV_PATH_NAME="OpenCV"'
    else
      r = run_command('test', '-d', opencv_prefix + '/share/opencv4')
      if r.returncode() == 0
        gstopencv_cargs += '-DOPENCV_PATH_NAME="opencv4"'
      else
        error('Unable to detect OpenCV data directory')
        opencv_found = false
      endif
    endif
  endif
endif

if opencv_found
  gstopencv = library('gstopencv',
    gstopencv_sources,
    cpp_args : gst_plugins_bad_args + gstopencv_cargs + [ '-DGST_USE_UNSTABLE_API' ],
    link_args : noseh_link_args,
    include_directories : [configinc],
    dependencies : [gstbase_dep, gstvideo_dep, opencv_dep, gstopencv_dep],
    install : true,
    install_dir : plugins_install_dir,
  )
endif
