#include <v8.h>
#include <node.h>
#include <clutter/clutter.h>
#include <clutter/x11/clutter-x11.h>

#include "clutter.hpp"
#include "actor.hpp"
#include "container.hpp"
#include "group.hpp"
#include "stage.hpp"
#include "rectangle.hpp"
#include "text.hpp"
#include "texture.hpp"

namespace clutter {
 
using namespace node;
using namespace v8;
 
static Handle<Value> ClutterInit(const Arguments& args)
{
	HandleScope scope;

	return scope.Close(Integer::New(clutter_init(NULL, NULL)));
}

static Handle<Value> ClutterMain(const Arguments& args)
{
	clutter_main();

	return Undefined();
}

static Handle<Value> SetUseARGBVisual(const Arguments& args)
{
	if (args[0]->IsBoolean()) {
		clutter_x11_set_use_argb_visual(args[0]->ToBoolean()->Value());
	}

	return Undefined();
}

static Handle<Value> ClutterMainQuit(const Arguments& args)
{
	clutter_main_quit();

	return Undefined();
}
 
extern "C" {
	static void init(Handle<Object> target)
	{
		HandleScope scope;

		/* Error conditions for initializing*/
		CLUTTER_DEFINE_CONSTANT(target, "INIT_SUCCESS", CLUTTER_INIT_SUCCESS);
		CLUTTER_DEFINE_CONSTANT(target, "INIT_UNKNOWN", CLUTTER_INIT_ERROR_UNKNOWN);
		CLUTTER_DEFINE_CONSTANT(target, "INIT_THREADS", CLUTTER_INIT_ERROR_THREADS);
		CLUTTER_DEFINE_CONSTANT(target, "INIT_BACKEND", CLUTTER_INIT_ERROR_BACKEND);
		CLUTTER_DEFINE_CONSTANT(target, "INIT_INTERNAL", CLUTTER_INIT_ERROR_INTERNAL);

		/* ClutterGravity */
		CLUTTER_DEFINE_CONSTANT(target, "GRAVITY_NONE", CLUTTER_GRAVITY_NONE);
		CLUTTER_DEFINE_CONSTANT(target, "GRAVITY_NORTH", CLUTTER_GRAVITY_NORTH);
		CLUTTER_DEFINE_CONSTANT(target, "GRAVITY_NORTH_EAST", CLUTTER_GRAVITY_NORTH_EAST);
		CLUTTER_DEFINE_CONSTANT(target, "GRAVITY_EAST", CLUTTER_GRAVITY_EAST);
		CLUTTER_DEFINE_CONSTANT(target, "GRAVITY_SOUTH_EAST", CLUTTER_GRAVITY_SOUTH_EAST);
		CLUTTER_DEFINE_CONSTANT(target, "GRAVITY_SOUTH", CLUTTER_GRAVITY_SOUTH);
		CLUTTER_DEFINE_CONSTANT(target, "GRAVITY_SOUTH_WEST", CLUTTER_GRAVITY_SOUTH_WEST);
		CLUTTER_DEFINE_CONSTANT(target, "GRAVITY_CENTER", CLUTTER_GRAVITY_CENTER);

		/* ClutterRotateAxis */
		CLUTTER_DEFINE_CONSTANT(target, "X_AXIS", CLUTTER_X_AXIS);
		CLUTTER_DEFINE_CONSTANT(target, "Y_AXIS", CLUTTER_Y_AXIS);
		CLUTTER_DEFINE_CONSTANT(target, "Z_AXIS", CLUTTER_Z_AXIS);

		/* ClutterRotateDirection */
		CLUTTER_DEFINE_CONSTANT(target, "ROTATE_CW", CLUTTER_ROTATE_CW);
		CLUTTER_DEFINE_CONSTANT(target, "ROTATE_CCW", CLUTTER_ROTATE_CCW);

		/* ClutterAlpha */
		CLUTTER_DEFINE_CONSTANT(target, "CUSTOM_MODE", CLUTTER_CUSTOM_MODE);

		/* linear */
		CLUTTER_DEFINE_CONSTANT(target, "LINEAR", CLUTTER_LINEAR);

		/* quadratic */
		CLUTTER_DEFINE_CONSTANT(target, "EASE_IN_QUAD", CLUTTER_EASE_IN_QUAD);
		CLUTTER_DEFINE_CONSTANT(target, "EASE_OUT_QUAD", CLUTTER_EASE_OUT_QUAD);
		CLUTTER_DEFINE_CONSTANT(target, "EASE_IN_OUT_QUAD", CLUTTER_EASE_IN_OUT_QUAD);

		/* cubic */
		CLUTTER_DEFINE_CONSTANT(target, "EASE_IN_CUBIC", CLUTTER_EASE_IN_CUBIC);
		CLUTTER_DEFINE_CONSTANT(target, "EASE_OUT_CUBIC", CLUTTER_EASE_OUT_CUBIC);
		CLUTTER_DEFINE_CONSTANT(target, "EASE_IN_OUT_CUBIC", CLUTTER_EASE_IN_OUT_CUBIC);

		/* quartic */
		CLUTTER_DEFINE_CONSTANT(target, "EASE_IN_QUART", CLUTTER_EASE_IN_QUART);
		CLUTTER_DEFINE_CONSTANT(target, "EASE_OUT_QUART", CLUTTER_EASE_OUT_QUART);
		CLUTTER_DEFINE_CONSTANT(target, "EASE_IN_OUT_QUART", CLUTTER_EASE_IN_OUT_QUART);

		/* quintic */
		CLUTTER_DEFINE_CONSTANT(target, "EASE_IN_QUINT", CLUTTER_EASE_IN_QUINT);
		CLUTTER_DEFINE_CONSTANT(target, "EASE_OUT_QUINT", CLUTTER_EASE_OUT_QUINT);
		CLUTTER_DEFINE_CONSTANT(target, "EASE_IN_OUT_QUINT", CLUTTER_EASE_IN_OUT_QUINT);

		/* sinusoidal */
		CLUTTER_DEFINE_CONSTANT(target, "EASE_IN_SINE", CLUTTER_EASE_IN_SINE);
		CLUTTER_DEFINE_CONSTANT(target, "EASE_OUT_SINE", CLUTTER_EASE_OUT_SINE);
		CLUTTER_DEFINE_CONSTANT(target, "EASE_IN_OUT_SINE", CLUTTER_EASE_IN_OUT_SINE);

		/* exponential */
		CLUTTER_DEFINE_CONSTANT(target, "EASE_IN_EXPO", CLUTTER_EASE_IN_EXPO);
		CLUTTER_DEFINE_CONSTANT(target, "EASE_OUT_EXPO", CLUTTER_EASE_OUT_EXPO);
		CLUTTER_DEFINE_CONSTANT(target, "EASE_IN_OUT_EXPO", CLUTTER_EASE_IN_OUT_EXPO);

		/* circular */
		CLUTTER_DEFINE_CONSTANT(target, "EASE_IN_CIRC", CLUTTER_EASE_IN_CIRC);
		CLUTTER_DEFINE_CONSTANT(target, "EASE_OUT_CIRC", CLUTTER_EASE_OUT_CIRC);
		CLUTTER_DEFINE_CONSTANT(target, "EASE_IN_OUT_CIRC", CLUTTER_EASE_IN_OUT_CIRC);

		/* elastic */
		CLUTTER_DEFINE_CONSTANT(target, "EASE_IN_ELASTIC", CLUTTER_EASE_IN_ELASTIC);
		CLUTTER_DEFINE_CONSTANT(target, "EASE_OUT_ELASTIC", CLUTTER_EASE_OUT_ELASTIC);
		CLUTTER_DEFINE_CONSTANT(target, "EASE_IN_OUT_ELASTIC", CLUTTER_EASE_IN_OUT_ELASTIC);

		/* overshooting cubic */
		CLUTTER_DEFINE_CONSTANT(target, "EASE_IN_BACK", CLUTTER_EASE_IN_BACK);
		CLUTTER_DEFINE_CONSTANT(target, "EASE_OUT_BACK", CLUTTER_EASE_OUT_BACK);
		CLUTTER_DEFINE_CONSTANT(target, "EASE_IN_OUT_BACK", CLUTTER_EASE_IN_OUT_BACK);

		/* exponentially decaying parabolic */
		CLUTTER_DEFINE_CONSTANT(target, "EASE_IN_BOUNCE", CLUTTER_EASE_IN_BOUNCE);
		CLUTTER_DEFINE_CONSTANT(target, "EASE_OUT_BOUNCE", CLUTTER_EASE_OUT_BOUNCE);
		CLUTTER_DEFINE_CONSTANT(target, "EASE_IN_OUT_BOUNCE", CLUTTER_EASE_IN_OUT_BOUNCE);

		/* own events */
		CLUTTER_DEFINE_CONSTANT(target, "EVENT_CLICK", NODE_CLUTTER_EVENT_CLICK);
		CLUTTER_DEFINE_CONSTANT(target, "EVENT_LONG_PRESS", NODE_CLUTTER_EVENT_LONG_PRESS);
		CLUTTER_DEFINE_CONSTANT(target, "EVENT_ENTER", NODE_CLUTTER_EVENT_ENTER);
		CLUTTER_DEFINE_CONSTANT(target, "EVENT_LEAVE", NODE_CLUTTER_EVENT_LEAVE);
		CLUTTER_DEFINE_CONSTANT(target, "EVENT_MOTION", NODE_CLUTTER_EVENT_MOTION);

		NODE_SET_METHOD(target, "init", ClutterInit);
		NODE_SET_METHOD(target, "main", ClutterMain);
		NODE_SET_METHOD(target, "quit", ClutterMainQuit);
		NODE_SET_METHOD(target, "useARGB", SetUseARGBVisual);

		Actor::Initialize(target);
		Container::Initialize(target);
		Group::Initialize(target);
		Stage::Initialize(target);
		Rectangle::Initialize(target);
		Text::Initialize(target);
		Texture::Initialize(target);
	}

	NODE_MODULE(clutter, init);
}

}
