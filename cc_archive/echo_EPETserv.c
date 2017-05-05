/*
  c tcpip ==> 엣지트리거를 사용해 epoll 서버를 구현한 예제 코드
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 4
#define EPOLL_SIZE 50

void  setnonblockingmode(int fd)
{
  int flag = fcntl(fd, F_GETFL, 0);
  fcntl(fd, F_SETFL, flag | O_NONBLOCK);
}

void  error_handling(char *buf )
{
  fputs(buf, stderr);
  fputc('\n',stderr);
  exit(1);
}

void main(int argc, char *argv[])
{
  int serv_sock, clnt_sock;
  struct sockaddr_in serv_adr, clnt_adr;
  socklen_t adr_sz;
  int str_len, i;
  char buf[BUF_SIZE];
  struct epoll_event *ep_events;
  struct epoll_event event;
  int epfd, event_cnt;

  if (argc != 2)
  {
   printf("usage \n");
   exit(1);
  }

  serv_sock = socket(PF_INET, SOCK_STREAM, 0);

  memset(&serv_adr, 0, sizeof(serv_adr));
  serv_adr.sin_family = AF_INET;
  serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_adr.sin_port = htons(atoi(argv[1]));

  if (bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
  {
    error_handling("bind() error");
  }

  if (listen(serv_sock,5) == -1 )
  {
    error_handling("listen() erorr");
  }

  epfd = epoll_create(EPOLL_SIZE);
  ep_events = malloc(sizeof(struct epoll_event)*EPOLL_SIZE);

  setnonblockingmode(serv_sock);   // 엣지 트리거를 사용한 코드
  event.events =EPOLLIN;
  event.data.fd = serv_sock;
  epoll_ctl(epfd, EPOLL_CTL_ADD, serv_sock, &event );

    while (1)
  {
    event_cnt = epoll_wait(epfd, ep_events, EPOLL_SIZE, -1);  // 프로그램이 시작하면 여기서 대기한다

    if (event_cnt == -1)
    {
      puts("epoll_wait() error");
      break;
    }

    puts("return epoll_wait");
    for (i = 0; i<event_cnt; i++)
    {
      if (ep_events[i].data.fd == serv_sock)
      {
        adr_sz = sizeof(clnt_adr);
        clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &adr_sz);
        event.events = EPOLLIN | EPOLLET;    // 엣지 트리거를 사용한 코드
        event.data.fd = clnt_sock;
        epoll_ctl(epfd, EPOLL_CTL_ADD, clnt_sock, &event);
        printf("connected client: %d\n", clnt_sock);
      }
      else
      {
        str_len = read(ep_events[i].data.fd, buf, BUF_SIZE);
        if (str_len == 0)
        {
          epoll_ctl(epfd, EPOLL_CTL_DEL, ep_events[i].data.fd, NULL);
          close(ep_events[i].data.fd);
          printf("closed client: %d\n", ep_events[i].data.fd);
        }
        else
        {
          write(ep_events[i].data.fd , buf , str_len);
        }
      }
    }
  }
  close(serv_sock);
  close(epfd);
}
