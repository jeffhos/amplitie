require 'rubygems' if RUBY_VERSION < '1.9'
require 'rake/builder'

Rake::Builder.new do |builder|
  builder.target = 'main'
  builder.source_search_paths = ['src']
  builder.objects_path        = 'obj'
  builder.library_dependencies += ['sfml-graphics', 'sfml-window', 'sfml-system']
end
