// state machine

#include <stdio.h>

enum state{idle, load_cfg, init_buf, init_threads, connect_devices, run, close, err_handler, exit};

int caller(int (*state_func)())
{
	return state_func();
}

// state functions
int idle_func()
{
	printf("State: idle\n");
	return load_cfg;
}


int load_cfg_func()
{
	char act = 'l';
	printf("State: load_cfg\n");
	printf("Input E:Exit, others:load_cfg\n");
	scanf("%c", &act);
	if (act == 'E' || act == 'e')
		return close;
	else
		return load_cfg;
}


int close_func()
{
	printf("State: close\n");
	return exit;
}


int main ()
{
	enum state curr_state = idle;

	while(curr_state != exit)
	{
	switch(curr_state)
	{
		// load configuration file
		case load_cfg:
			curr_state = caller(load_cfg_func);
		break;
		
		//exit
		case close:
			curr_state = caller(close_func);			
		break;
		
		default:
			curr_state = caller(idle_func);
	}
	}
}
