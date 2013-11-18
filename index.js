var binding = require('bindings')('gcore');

var VALID_PLATFORMS = ['linux'];

exports.gcore = function(name) {
  var idx = VALID_PLATFORMS.indexOf(process.platform);

  if (idx === -1) {
    console.trace("This platform is not supported by the gcore module:",
                  process.platform);
    return false;
  }

	var ret = binding.gcore(name);

  return ret === 0 ? true : false;
};
