type
        hd=record
                x:byte;
                y:byte;
                kt:boolean;
        end;
var
        a:array[0..200,0..200] of boolean;
        d:array[0..1] of longint;
        da,db:array[1..200] of hd;
        kq:int64;
        n,m,k,i,j,d1,d2,dem,x1,y1,t,kx,ky:longint;
        kt:boolean;
procedure nhap;
begin
        readln(t);
        while t>0 do
        begin
        dec(t);
        readln(n,m,k);
        d1:=0;
        d2:=0;
        fillchar(a,sizeof(a),false);
        d1:=0;d2:=0;
        kq:=0;
        for i:=1 to k do
        begin
                readln(x1,y1);
                inc(d[(x1+y1)mod 2]);
                a[x1,y1]:=true;
                if (x1+y1) mod 2=0 then
                begin
                        inc(d1);
                        da[d1].x:=x1;
                        da[d1].y:=y1;
                        da[d1].kt:=true;
                end
                else
                begin
                        inc(d2);
                        db[d2].x:=x1;
                        db[d2].y:=y1;
                        db[d2].kt:=true;
                end;
        end;
        if (n mod 2=0) or (m mod 2=0) then
        begin
                if k>(n*m div 2) then
                begin
                        writeln(-1);
                        exit;
                end;
        end
        else
        begin
                if k>((n*m+1) div 2) then
                begin
                        writeln(-1);
                        exit;
                end;
        end;
                if d[0]>d[1] then
                begin
                repeat
                        for i:=1 to d2 do
                        begin
                                kx:=db[i].x;
                                ky:=db[i].y;
                                if (db[i].kt) and ((a[kx-1,ky]) or (a[kx,ky+1]) or(a[kx+1,ky]) or (a[kx,ky-1])) then
                                begin
                                        kt:=false;
                                        db[i].kt:=false;
                                        a[kx,ky]:=false;
                                        for j:=1 to n do
                                        begin
                                                if kt then break;
                                                for k:=1 to m do
                                                if (a[j,k]=false) and ((j+k) mod 2=0)then
                                                begin
                                                        a[j,k]:=true;
                                                        inc(kq);
                                                        kt:=true;
                                                        break;
                                                end;
                                        end;
                                end;
                        end;
                        kt:=true;
                        for i:=1 to n do
                        begin
                                if kt=false then break;
                                for j:=1 to m do
                                if (a[i,j]) and ((a[i-1,j]) or (a[i,j+1]) or (a[i+1,j]) or (a[i,j-1])) then
                                begin
                                        kt:=false;
                                        break;
                                end;
                        end;
                until kt=true;
                end
                else
                begin
                repeat
                        for i:=1 to d1 do
                        begin
                                kx:=da[i].x;
                                ky:=da[i].y;
                                if (da[i].kt) and ((a[kx-1,ky]) or (a[kx,ky+1]) or(a[kx+1,ky]) or (a[kx,ky-1])) then
                                begin
                                        kt:=false;
                                        da[i].kt:=false;
                                        a[kx,ky]:=false;
                                        for j:=1 to n do
                                        begin
                                                if kt then break;
                                                for k:=1 to m do
                                                if (a[j,k]=false) and ((j+k) mod 2=1)then
                                                begin
                                                        a[j,k]:=true;
                                                        inc(kq);
                                                        kt:=true;
                                                        break;
                                                end;
                                        end;
                                end;
                        end;
                        kt:=true;
                        for i:=1 to n do
                        begin
                                if kt=false then break;
                                for j:=1 to m do
                                if (a[i,j]) and ((a[i-1,j]) or (a[i,j+1]) or (a[i+1,j]) or (a[i,j-1])) then
                                begin
                                        kt:=false;
                                        break;
                                end;
                        end;
                until kt=true;
                end;
        end;
        {for i:=1 to n do
                for j:=1 to m do
                        if a[i,j] then writeln(i,' ',j);  }
        writeln(kq);
end;
begin
        assign(input,'room.inp');
        assign(output,'room.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.