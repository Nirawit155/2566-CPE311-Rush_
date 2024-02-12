
# เกมส์เศรษฐี
วัตถุประสงค์ของโครงการนี้จัดทำเพื่อนำความรู้ที่ศึกษามาจากรายวิชา CPE-311/CPE-312 มาประยุกต์ให้เข้ากับบอร์ดเกมจากอุปกรณ์ที่ได้ศึกษาต่างๆจากการเรียนภาคปฎิบัติเพื่อสร้างลูกเล่นให้สอดคล้องกับรายวิชา

# สารบัญ

-   [ความต้องการของโครงการ](#%E0%B8%84%E0%B8%A7%E0%B8%B2%E0%B8%A1%E0%B8%95%E0%B9%89%E0%B8%AD%E0%B8%87%E0%B8%81%E0%B8%B2%E0%B8%A3%E0%B8%82%E0%B8%AD%E0%B8%87%E0%B9%82%E0%B8%84%E0%B8%A3%E0%B8%87%E0%B8%81%E0%B8%B2%E0%B8%A3)
-   [อุปกรณ์ที่ใช้](#%E0%B8%AD%E0%B8%B8%E0%B8%9B%E0%B8%81%E0%B8%A3%E0%B8%93%E0%B9%8C%E0%B8%97%E0%B8%B5%E0%B9%88%E0%B9%83%E0%B8%8A%E0%B9%89)
-   [ช่องpinที่ใช้](#%E0%B8%8A%E0%B9%88%E0%B8%AD%E0%B8%87pin%E0%B8%97%E0%B8%B5%E0%B9%88%E0%B9%83%E0%B8%8A%E0%B9%89)
- [Board-Designed](#board-designed)
-   [ตารางเวลาการทำโครงการ](#%E0%B8%95%E0%B8%B2%E0%B8%A3%E0%B8%B2%E0%B8%87%E0%B9%80%E0%B8%A7%E0%B8%A5%E0%B8%B2%E0%B8%81%E0%B8%B2%E0%B8%A3%E0%B8%97%E0%B8%B3%E0%B9%82%E0%B8%84%E0%B8%A3%E0%B8%87%E0%B8%81%E0%B8%B2%E0%B8%A3)

## ความต้องการของโครงการ

 1.  Player ของเกมนี้จะมีทั้งหมด 2 คน
 2.  แสดงสถานะจำนวนเงินของผู้เล่น(ใช้ 7 segment)
 3.  Player แต่ละคนจะมีปุ่ม Action อยู่ 2 ปุ่ม
	ปุ่มที่ 1 จะเป็นปุ่มทอยลูกเต๋าและยกเลิก Action (ไม่ซื้อเมือง ) ปุ่มที่ 2 จะเป็นปุ่มทอยลูกเต๋าและยอมรับ Action ( การซื้อเมือง )
 4.  แสดงสถานะตำแหน่งของผู้เล่นว่าอยู่ตำแหน่งไหนและตำแหน่งของบ้านผู้เล่นที่ซื้อไปผ่าน LED แต่ละสี เช่น สีเขียว , สีแดง
 5.  แสดงว่าอยู่ในรอบของผู้เล่นโดยการกระพริบของไฟ LED แสดงตำแหน่งของผู้เล่น
 6.  แสดงผลทอยลูกเต๋าที่ได้บน ไฟ LED โดยจะมีลูกเต๋า 1 ลูก ( 6 แต้ม )
 7.  ขนาดของบอร์ดจะเป็นแบบด้านละ 5 ช่อง โดยจะมี event 4 ช่อง(อยู่ที่หัวมุมทั้ง 4) และมีบ้านทั้งกระดานรวม 12 ช่อง(ด้านละ 3 ช่องจาก 5 ช่อง)
 8.  Event จะมี 4 Event
 9.  Start (เมื่อวนครบรอบก็จะได้เงินเดือน)
 10.  หยุดที่เกาะร้าง (จะต้องหยุดที่เกาะล้างโดยเมื่ออยากจะออกจากเกาะร้างสามารถเลือกได้ 2 กรณี 1.ทอยลูกเต๋าออกอย่างน้อย 4 แต้มถึงจะออกได้ 2.จ่ายเงินออก
 11.  สุ่มจำนวนเงิน
 12.  เสียภาษี
 13.  ตอนจบเกมจะมีเพลงแจ้งเตือนและLED ทุกดวงจะแสดงสีเป็นของคนชนะ ( เมื่อมีคนแพ้หรือชนะ )
 14.  จะมีปุ่มแดง เมื่อกดจะทำการ Reset game ทั้งหมด
 

# อุปกรณ์ที่ใช้

 1. 7segment 2 ชิ้น
 2. resistor(1k) 10 ชิ้น
 3. resistor(330) 18 ชิ้น
 4. transistor(2N4401) 8 ชิ้น
 5. switch 4 ชิ้น
 6. LED 7 ชิ้น
 7. LED(rgb) 28 ชิ้น
 8. A lot of wires

# ช่องpinที่ใช้
![enter image description here](https://media.discordapp.net/attachments/1195246143551058003/1205443256712831026/Pin.png?ex=65d86384&is=65c5ee84&hm=0d2cbaf7635f4895cb187ffe2a281eaa7d8fe4509ad0c59d6c76ba164329bedb&=&format=webp&quality=lossless)
![enter image description here](https://media.discordapp.net/attachments/1195246143551058003/1205443312538877962/Pin.png?ex=65d86391&is=65c5ee91&hm=11fbfef4d3e7af68b8e6a9fe30527897d143e0af0cdb9dc48288c2696210178f&=&format=webp&quality=lossless&width=823&height=671)



## DIAGRAM
![enter image description here](https://media.discordapp.net/attachments/1195246143551058003/1205443491614826537/PlayerAndDiceBoard_Diagram.jpg?ex=65d863bc&is=65c5eebc&hm=5ab641c7a5ffec2b8163ccdba5111631f6c51ad13e04353baf35bdf33b6fcc09&=&format=webp&width=523&height=671)


# Board-Designed
![enter image description here](https://cdn.discordapp.com/attachments/1195246143551058003/1202596198490439691/1070087967294631976-283cde1b-df1c-47c1-83b5-60bda2ece5a2-6059968.399999976.png?ex=65ce07fc&is=65bb92fc&hm=589a5289ea82545f37a57a66f3a5ebd98d0fafb5d8d49b11d4c6412e6c27ccb6&)
## ตารางเวลาการทำโครงการ
![enter image description here](https://media.discordapp.net/attachments/744332116808171530/1205265035031486564/image.png?ex=65d7bd89&is=65c54889&hm=60fed954cb2ea19ff145199a7e738a2de8978e228ff350bfb6f5badb4454cddc&=&format=webp&quality=lossless&width=962&height=285)
