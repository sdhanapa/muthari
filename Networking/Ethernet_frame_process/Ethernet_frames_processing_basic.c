#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>


typedef struct {
    uint8_t src_addr[6];
    uint8_t dst_addr[6];
    uint16_t etherType;
}EthernetHeader;


bool isBigendian(int data){
    char *ch_ptr = (char*)&data;
    //printf("MSB addr = %04x, LSB addr = %x\n",&ch_ptr[0],&ch_ptr[1]);
    if(ch_ptr[0] == 0x00){
        //printf("MSB %02x is in lower addr, Bigendian addr = %x\n",ch_ptr[0],&ch_ptr[0]);
        return true;
    } else {
        //printf("LSB %02x is in lower addr, Littleendian addr = %x\n",ch_ptr[1],&ch_ptr[1]);
        return false;
    }
}

int converToBigEndian(int data){
    
    int a = ((data << 4) & 0xFF00) ; //| ((data << 4) & 0xFF00)
    printf(" shifter output = %x\n",a);
    return a;
}


void CheckPayloadType(uint16_t data) {
    switch(data) {
        case 0x0800: 
        printf("Payload type: IPv4\n");
        break;
        case 0x0806:
        printf("Payload type: IPv4\n");
        break;  
        case 0x86DD:
        printf("Payload type: IPv4\n");
        break;
        default:
        printf("Payload type: IPv4\n");
        break;        
    }
}
void print_mac(const char* name, const uint8_t* mac) {
    printf("%s mac is %02X:%02X:%02X:%02X:%02X:%02X\n",name,mac[0],mac[1],mac[2],mac[3],mac[4],mac[5]);
}

void parse_frame(uint8_t frame[], size_t frame_len) {
    
    //Check if frame is greater than minimum ethernet header size, [14 - without payload].
    if(frame_len < 14) { 
        printf("Invalid frame size\n");
        return;
    }
    
    //Caste the ethernet frame to local structure
    EthernetHeader *EthHdr = (EthernetHeader*)frame; // casting array to struct.
    
    //Get src and dst from local struct
    print_mac("source",EthHdr->src_addr);
    print_mac("source",EthHdr->dst_addr);
    
    //Get EtherType from Local struct
    printf("Before BigEndian convertion Ethernet Type is %04X\n",EthHdr->etherType);
    
    //Check is given frame is BigEndian?
    (isBigendian(EthHdr->etherType))?printf("BigEndian\n"):printf("LittleEndian\n");
	
    //Convert to BigEndian
    EthHdr->etherType = converToBigEndian(EthHdr->etherType);
    printf("After BigEndian convertion Ethernet Type is %04X\n",EthHdr->etherType);
    
    //Determine the payload type based on the Ethernet Type
    CheckPayloadType(EthHdr->etherType);
    
    //printing payload if any
    size_t p_size = frame_len - 14;
    if(p_size) {
        for(int i =0;i<p_size;i++) {
            printf("0x%02x ",frame[14+i]);
        }
    }
}


int main() {
    uint8_t frame[] = {
        // Destination MAC: 00:11:22:33:44:55
        0x00, 0x11, 0x22, 0x33, 0x44, 0x55,
        // Source MAC: 66:77:88:99:AA:BB
        0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB,
        // EtherType: IPv4 (0x0800)
        0x80, 0x00,
        // Payload (example data)
        0x45, 0x00, 0x00, 0x54, 0x00, 0x00, 0x40, 0x00,
        0x40, 0x01, 0x00, 0x00, 0xC0, 0xA8, 0x01, 0x01,
        0xC0, 0xA8, 0x01, 0x02};
        
        parse_frame(frame,sizeof(frame));
        return 0;
}


/*
Note: uint8_t is a typedef for an unsigned 8-bit integer,
ensures that the variable will always be exactly 8 bits (1 byte) in size, regardless of the system or compiler.
*/
