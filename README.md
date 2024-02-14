

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
 

# อุปกรณ์ที่ใช้
Equiqment: PositionBoard
1.LED(rgb) 28 pieces
2.A resistor(1k)
3.resistor(330) 2 pieces
4.A speaker
5.A transistor(2N4401)
6.A lot of wires

Equiqment: PlayerAndDice
1.7segment 2 pieces
2.resistor(1k) 13 pieces
3.resistor(330) 21 pieces
4.transistor(2N4401) 8 pieces
5.switch 5 pieces
6.LED 7 pieces
7.A lot of wires

# ช่องpinที่ใช้
![enter image description here](https://cdn.discordapp.com/attachments/1195246143551058003/1207348170795782246/1-1.jpg?ex=65df519b&is=65ccdc9b&hm=a48e55f9790d8354ba3bb5eeb4e0d50f6b1f1dcf883c29c87720b46c3d38b185&)
![enter image description here](https://media.discordapp.net/attachments/1195246143551058003/1207347084513124412/-1.jpg?ex=65df5098&is=65ccdb98&hm=0215f888c4918f8628d77caf0dff3dccde45b17ed0e3104f6c33ffd477c671a8&=&format=webp&width=822&height=671)



## DIAGRAM
![enter image description here](https://cdn.discordapp.com/attachments/1195246143551058003/1206936855824826418/image.png?ex=65ddd28a&is=65cb5d8a&hm=684853b2b2b824165118d6b92b8b11bb2f16d7c1efaa34ea8545f84a89746118&)
![enter image description here](https://cdn.discordapp.com/attachments/1195246143551058003/1207346447272513597/Screenshot_2024-02-14_222320.png?ex=65df5000&is=65ccdb00&hm=7fda4a5f4b8d7c6a1737107455e240ba87a6548f30a6b4124b76003b8a9ade7c&)

# Board-Designed
![enter image description here](https://cdn.discordapp.com/attachments/1195246143551058003/1202596198490439691/1070087967294631976-283cde1b-df1c-47c1-83b5-60bda2ece5a2-6059968.399999976.png?ex=65ce07fc&is=65bb92fc&hm=589a5289ea82545f37a57a66f3a5ebd98d0fafb5d8d49b11d4c6412e6c27ccb6&)
## ตารางเวลาการทำโครงการ
![enter image description here](https://cdn.discordapp.com/attachments/1195246143551058003/1207351700189618176/image.png?ex=65df54e4&is=65ccdfe4&hm=40a0070fc69798d504ced05a3541bdb940b9ccddf623bfaf5f093a9cd593df01&)
