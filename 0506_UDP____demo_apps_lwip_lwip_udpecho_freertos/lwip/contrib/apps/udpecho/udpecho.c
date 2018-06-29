#include "udpecho.h"

#include "lwip/opt.h"

#if LWIP_NETCONN

#include "lwip/api.h"
#include "lwip/sys.h"

uint16_t GlobalBuffer[200];

//struct netbuf *GlobalBuffer;

//struct netbuf* AudioPlayer_getBuffer()
//{
//	return buf_send;
//}

uint16_t* AudioPlayer_getBuffer()
{
	return GlobalBuffer;
}

static void server_thread(void *arg)
{
	struct netconn *conn;
	struct netbuf *buf;

	uint16_t *msg;

	uint16_t len;
//	uint16_t buffer[200];
	//	memset(buffer[0], 0, sizeof(buffer[0]));

	LWIP_UNUSED_ARG(arg);
	conn = netconn_new(NETCONN_UDP);
	netconn_bind(conn, IP_ADDR_ANY, 54321);//ip4

	synchroTaskSemaphore = xSemaphoreCreateBinary();


	while (1)
	{
		xSemaphoreTake(synchroTaskSemaphore,portMAX_DELAY);
		netconn_recv(conn, &buf);
		netbuf_data(buf, (void**)&msg, &len);//CREO NO ES NECESARIA ESTA LINEA

		//PRINTF("%i" ,msg[0]);

		netbuf_copy(buf, GlobalBuffer, sizeof(GlobalBuffer));//ESTA ES LA BUENA
		//PRINTF("%i ", buffer[0]);
//		int8_t i;
//
//		for( i=0 ;i<len;i++){
//			GlobalBuffer[i]=buffer[i];
//
//		}

		//		buf_send=buf;

		netbuf_delete(buf);

	}


}

/*-----------------------------------------------------------------------------------*/
//static void
//client_thread(void *arg)
//{
//	ip_addr_t dst_ip;
//	struct netconn *conn;
//	struct netbuf *buf;
//
//	LWIP_UNUSED_ARG(arg);
//	conn = netconn_new(NETCONN_UDP);
//	//LWIP_ERROR("udpecho: invalid conn", (conn != NULL), return;);
//
//	char *msg = "Hello loopback!";
//	buf = netbuf_new();
//	netbuf_ref(buf,msg,10);
//
//	IP4_ADDR(&dst_ip, 127, 0, 0, 1);
//
//	while (1)
//	{
//		netconn_sendto(conn, buf, &dst_ip, 50005);
//		vTaskDelay(1000);
//	}
//}
/*-----------------------------------------------------------------------------------*/
void udpecho_init(void)
{

	//	sys_thread_new("client", client_thread, NULL, 300, 1);
	sys_thread_new("server", server_thread, NULL, 300, 2);

}

#endif /* LWIP_NETCONN */
