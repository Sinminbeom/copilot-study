#include <iostream>
#include <pcap.h>
using namespace std;

// udp 패킷을 캡처해서 pcap 파일로 저장하는 함수
void savePcapFile() {
    pcap_t *handle = pcap_open_live("any", BUFSIZ, 1, 1000, NULL);
    if (handle == NULL) {
        cout << "pcap_open_live() error" << endl;
        return;
    }

    // Apply a filter to capture only UDP packets
    struct bpf_program fp;
    char filter_exp[] = "udp port 5010";
    if (pcap_compile(handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        cout << "pcap_compile() error" << endl;
        return;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        cout << "pcap_setfilter() error" << endl;
        return;
    }

    pcap_dumper_t *dump = pcap_dump_open(handle, "test0.pcap");
    if (dump == NULL) {
        cout << "pcap_dump_open() error" << endl;
        return;
    }
    
    // 이 pcap_loop 함수는 패킷을 캡처해서 pcap_dump 함수를 호출하는 역할을 한다.
    pcap_loop(handle, 0, pcap_dump, (u_char *)dump);

    pcap_dump_close(dump);
    pcap_close(handle);
}


// pcap 파일을 읽어서 timestamp를 출력하는 함수
void printPcapFile(const char *pcapPath) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_offline(pcapPath, errbuf);
    if (handle == NULL) {
        cout << "pcap_open_offline() error" << endl;
        return;
    }

    struct pcap_pkthdr *header;
    const u_char *packet;
    int res;
    while ((res = pcap_next_ex(handle, &header, &packet)) >= 0) {
        if (res == 0) continue;

        // timestamp의 초와 나노초를 .으로 구분해서 출력
        cout << header->ts.tv_sec << "." << header->ts.tv_usec << endl;
    }

    pcap_close(handle);
}


int main() {
    savePcapFile();
    // printPcapFile("test01.pcap");
    return 0;
}
