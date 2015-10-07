require 'rubygems' if RUBY_VERSION < '1.9'
require 'rake/builder'

Rake::Builder.new do |builder|
  builder.target = 'main'
  builder.source_search_paths = ['src', 'src/arduino']
  builder.compilation_options << '-std=c++11'
  builder.objects_path        = 'obj'
  builder.library_dependencies += ['sfml-graphics', 'sfml-window', 'sfml-system', 'sfml-audio']
  builder.architecture = 'x86_64'
end
