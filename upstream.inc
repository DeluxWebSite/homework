upstream example_app {

	server 192.168.220.158:8888 weight=3;
        server 192.168.220.208:9999;

}
