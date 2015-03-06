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

  if (ret === 0) {
    return true;
  } else {
    console.trace("Core file failed to be created with errno: %d", ret);
    return false;
  }
};
