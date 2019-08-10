type
        gt=record
                s:longint;
                kt:boolean;
        end;
        arr=record
                s:longint;
                kt:boolean;
        end;
        ar=array[1..8,1..8] of arr;
var
        f:ar;
        i,j,k:longint;
        max:int64;
        dd:array[1..4] of boolean;
procedure nhap;
var     x,y,v:longint;
begin
        for i:=1 to 8 do
                for j:=1 to 8 do
                        f[i,j].kt:=false;
        readln(k);
        for i:=1 to k do
        begin
                readln(x,y,v);
                f[y,x].kt:=true;
                f[y,x].s:=v;
        end;
end;
function tinh(f:ar;w,x,y:longint):longint;
var     cross,diagon,tmp1,tmp2,horse:longint;
begin
        cross:=0;diagon:=0;horse:=0;
        if w=1 then
        begin
                for i:=1 to 8 do
                begin
                        if (f[x,i].kt) then inc(cross,f[x,i].s);
                        if (f[i,y].kt) then inc(cross,f[i,y].s);
                end;
                cross:=cross-2*f[x,y].s;
                tmp1:=x-1;tmp2:=y-1;
                while (tmp1>=1) and (tmp2>=1) do
                begin
                        if f[tmp1,tmp2].kt then inc(diagon,f[tmp1,tmp2].s);
                        dec(tmp1);dec(tmp2);
                end;
                tmp1:=x-1;tmp2:=y+1;
                while (tmp1>=1) and (tmp2<=8) do
                begin
                        if f[tmp1,tmp2].kt then inc(diagon,f[tmp1,tmp2].s);
                        dec(tmp1);inc(tmp2);
                end;
                tmp1:=x+1;tmp2:=y+1;
                while (tmp1<=8) and (tmp2<=8) do
                begin
                        if f[tmp1,tmp2].kt then inc(diagon,f[tmp1,tmp2].s);
                        inc(tmp1);inc(tmp2);
                end;
                tmp1:=x+1;tmp2:=y-1;
                while (tmp1<=8) and (tmp2>=1) do
                begin
                        if f[tmp1,tmp2].kt then inc(diagon,f[tmp1,tmp2].s);
                        inc(tmp1);dec(tmp2);
                end;
                exit(cross+diagon);
        end;
        if w=2 then
        begin
                for i:=1 to 8 do
                begin
                        if f[x,i].kt then inc(cross,f[x,i].s);
                        if f[i,y].kt then inc(cross,f[i,y].s);
                end;
                cross:=cross-2*f[x,y].s;
                exit(cross);
        end;
        if w=3 then
        begin
                tmp1:=x-1;tmp2:=y-1;
                while (tmp1>=1) and (tmp2>=1) do
                begin
                        if f[tmp1,tmp2].kt then inc(diagon,f[tmp1,tmp2].s);
                        dec(tmp1);dec(tmp2);
                end;
                tmp1:=x-1;tmp2:=y+1;
                while (tmp1>=1) and (tmp2<=8) do
                begin
                        if f[tmp1,tmp2].kt then inc(diagon,f[tmp1,tmp2].s);
                        dec(tmp1);inc(tmp2);
                end;
                tmp1:=x+1;tmp2:=y+1;
                while (tmp1<=8) and (tmp2<=8) do
                begin
                        if f[tmp1,tmp2].kt then inc(diagon,f[tmp1,tmp2].s);
                        inc(tmp1);inc(tmp2);
                end;
                tmp1:=x+1;tmp2:=y-1;
                while (tmp1<=8) and (tmp2>=1) do
                begin
                        if f[tmp1,tmp2].kt then inc(diagon,f[tmp1,tmp2].s);
                        inc(tmp1);dec(tmp2);
                end;
                exit(diagon);
        end;
        if w=4 then
        begin
                if (x>=2) and (y>=3) and (f[x-1,y-2].kt) then
                        inc(horse,f[x-1,y-2].s);
                if (x>=3) and (y>=2) and (f[x-2,y-1].kt) then
                        inc(horse,f[x-2,y-1].s);
                if (x>=3) and (y<=7) and (f[x-2,y+1].kt) then
                        inc(horse,f[x-2,y+1].s);
                if (x>=2) and (y<=6) and (f[x-1,y+2].kt) then
                        inc(horse,f[x-1,y+2].s);
                if (x<=7) and (y<=6) and (f[x+1,y+2].kt) then
                        inc(horse,f[x+1,y+2].s);
                if (x<=6) and (y<=7) and (f[x+2,y+1].kt) then
                        inc(horse,f[x+2,y+1].s);
                if (x<=6) and (y>=2) and (f[x+2,y-1].kt) then
                        inc(horse,f[x+2,y-1].s);
                if (x<=7) and (y>=3) and (f[x+1,y-2].kt) then
                        inc(horse,f[x+1,y-2].s);
                exit(horse);
        end;
end;
function change(f:ar;w,x,y:longint):ar;
var
        tmp1,tmp2,i:longint;
begin
        if w=1 then
        begin
                for i:=1 to 8 do
                begin
                        if f[i,x].s<>0 then f[i,x].kt:=false;
                        if f[y,i].s<>0 then f[y,i].kt:=false;
                end;
                tmp1:=x-1;tmp2:=y-1;
                while (tmp1>=1) and (tmp2>=1) do
                begin
                        f[tmp1,tmp2].kt:=false;
                        dec(tmp1);dec(tmp2);
                end;
                tmp1:=x-1;tmp2:=y+1;
                while (tmp1>=1) and (tmp2<=8) do
                begin
                        f[tmp1,tmp2].kt:=false;
                        dec(tmp1);inc(tmp2);
                end;
                tmp1:=x+1;tmp2:=y+1;
                while (tmp1<=8) and (tmp2<=8) do
                begin
                        f[tmp1,tmp2].kt:=false;
                        inc(tmp1);inc(tmp2);
                end;
                tmp1:=x+1;tmp2:=y-1;
                while (tmp1<=8) and (tmp2>=1) do
                begin
                        f[tmp1,tmp2].kt:=false;
                        inc(tmp1);dec(tmp2);
                end;
                f[x,y].kt:=true;
                exit(f);
        end;
        if w=2 then
        begin
                for i:=1 to 8 do
                begin
                        if f[i,x].s<>0 then f[i,x].kt:=false;
                        if f[y,i].s<>0 then f[y,i].kt:=false;
                end;
                f[x,y].kt:=true;
                exit(f);
        end;
        if w=3 then
        begin
                tmp1:=x-1;tmp2:=y-1;
                while (tmp1>=1) and (tmp2>=1) do
                begin
                        f[tmp1,tmp2].kt:=false;
                        dec(tmp1);dec(tmp2);
                end;
                tmp1:=x-1;tmp2:=y+1;
                while (tmp1>=1) and (tmp2<=8) do
                begin
                        f[tmp1,tmp2].kt:=false;
                        dec(tmp1);inc(tmp2);
                end;
                tmp1:=x+1;tmp2:=y+1;
                while (tmp1<=8) and (tmp2<=8) do
                begin
                        f[tmp1,tmp2].kt:=false;
                        inc(tmp1);inc(tmp2);
                end;
                tmp1:=x+1;tmp2:=y-1;
                while (tmp1<=8) and (tmp2>=1) do
                begin
                        f[tmp1,tmp2].kt:=false;
                        inc(tmp1);dec(tmp2);
                end;
                f[x,y].kt:=true;
                exit(f);
        end;
        if w=4 then
        begin
                if (x>=2) and (y>=3) and (f[x-1,y-2].kt) and (f[x-1,y-2].s<>0) then
                        f[x-1,y-2].kt:=false;
                if (x>=3) and (y>=2) and (f[x-2,y-1].kt) and (f[x-2,y-1].s<>0) then
                        f[x-2,y-1].kt:=false;
                if (x>=3) and (y<=7) and (f[x-2,y+1].kt) and (f[x-2,y+1].s<>0) then
                        f[x-2,y+1].kt:=false;
                if (x>=2) and (y<=6) and (f[x-1,y+2].kt) and (f[x-1,y+2].s<>0) then
                        f[x-1,y+2].kt:=false;
                if (x<=7) and (y<=6) and (f[x+1,y+2].kt) and (f[x+1,y+2].s<>0) then
                        f[x+1,y+2].kt:=false;
                if (x<=6) and (y<=7) and (f[x+2,y+1].kt) and (f[x+2,y+1].s<>0) then
                        f[x+2,y+1].kt:=false;
                if (x<=6) and (y>=2) and (f[x+2,y-1].kt) and (f[x+2,y-1].s<>0) then
                        f[x+2,y-1].kt:=false;
                if (x<=7) and (y>=3) and (f[x+1,y-2].kt) and (f[x+1,y-2].s<>0) then
                        f[x+1,y-2].kt:=false;
                f[x,y].kt:=true;
                exit(f);
        end;
end;
procedure try(f:ar;a:longint;t:int64);
var     i,j,w:longint;
begin
        for i:=1 to 8 do
                for j:=1 to 8 do
                if (f[i,j].kt=false) and (f[i,j].s=0) then
                begin
                        for w:=1 to 4 do
                        if dd[w] then
                        begin
                                dd[w]:=false;
                                if a=4 then
                                begin
                                        t:=t+tinh(f,w,i,j);
                                        if t>max then max:=t;
                                end
                                else try(change(f,w,i,j),a+1,t+tinh(f,w,i,j));
                                dd[w]:=true;
                        end;
                end;
end;
procedure xuly;
begin
        max:=0;
        fillchar(dd,sizeof(dd),true);
        try(f,1,0);
        writeln(max);
end;
begin
        assign(input,'bonus13.inp');
        assign(output,'bonus13.out');
        reset(input);
        rewrite(output);
        nhap;
        xuly;
        close(input);
        close(output);
end.


