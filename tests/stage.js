var clutter = require('../build/Release/clutter');

if (clutter.init() != clutter.INIT_SUCCESS) {
	console.log("Failed to initialize clutter.");
	process.exit();
}

/* Create a new stage */
var stage = new clutter.Stage();
stage.setTitle('This is a new stage');
stage.show();
stage.hide();
stage.showAll();

clutter.main();