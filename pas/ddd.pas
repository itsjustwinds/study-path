{uses math;
var
        a,b:array[0..51] of longint;
        i,j,n,m:longint;
        s:ansistring;

function swap(s:ansistring):ansistring;
var     i,j:longint;
        t:char;
begin
        for i:=0 to n-1 do
                for j:=1 to m div 2 do
                begin
                        t:=s[m*i+j];
                        s[m*i+j]:=s[m*i+m-j+1];
                        s[m*i+m-j+1]:=t;
                end;
        swap:=s;
end;

procedure xuly;
var     i:longint;
        kt:boolean;
begin
        s:='';
        for i:=1 to n*m do
                s:=s+'0';
        for i:=length(s) downto 1 do
                if (i mod m=0)then
                begin
                 if (a[i div m]>0) and (b[m]>0)then
                        begin
                                s[i]:='1';
                                dec(a[i div m]);
                                dec(b[m]);
                        end;
                end
                else
                if (a[(i div m)+1]>0) and (b[i mod m]>0) then
                begin
                                s[i]:='1';
                                dec(a[(i div m)+1]);
                                dec(b[i mod m]);
                end;
        kt:=true;
        for i:=1 to n do
                if a[i]<>0 then
                begin
                        kt:=false;
                        break;
                end;
        if kt then
                for i:=1 to m do
                        if b[i]<>0 then
                        begin
                                kt:=false;
                                break;
                        end;
        if kt then
                writeln(s)
        else writeln(-1);
end;
procedure nhap;
begin
        repeat
                readln(n,m);
                if (n<>0) or(m<>0) then
                begin
                for i:=1 to n do
                        read(a[i]);
                for i:=1 to m do
                        read(b[i]);
                xuly;
                end;
        until (n=0) and (m=0);
end;
begin
        assign(input,'ddd.inp');
        assign(output,'ddd.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.
}
var
        c:array[0..1] of char=('0','1');
        a,b:array[0..51] of longint;
        i,j,m,n:longint;
        check:boolean;
        s:ansistring;
procedure result;
var     kt:boolean;
begin
        kt:=true;
        for i:=1 to n do
                if a[i]<>0 then
                begin
                        kt:=false;
                        break;
                end;
        if kt then
                for i:=1 to m do
                        if b[i]<>0 then
                        begin
                                kt:=false;
                                break;
                        end;
        if kt then
        begin
                check:=true;
                writeln(s);
        end;
end;
procedure try(i:longint);
var     j:longint;
begin
        if check then exit;
        for j:=0 to 1 do
        begin
                if j=1 then
                begin
                        if i mod m=0 then
                        begin
                        if (a[i div m]>0) and (b[m]>0) then
                        begin
                                dec(a[i div m]);
                                dec(b[m]);
                                s:=s+c[j];
                                if i=m*n then result
                                else try(i+1);
                                inc(a[i div m]);
                                inc(b[m]);
                                delete(s,i,1);
                        end;
                        end
                        else if (a[i div m+1]>0) and (b[i mod m]>0) then
                        begin
                                dec(a[i div m+1]);
                                dec(b[i mod m]);
                                s:=s+c[j];
                                if i=m*n then result
                                else try(i+1);
                                inc(a[i div m+1]);
                                inc(b[i mod m]);
                                delete(s,i,1);
                        end;
                end
                else
                begin
                        s:=s+c[j];
                        if i=m*n then result
                        else try(i+1);
                        delete(s,i,1);
                end;
        end;
end;
procedure nhap;
begin
        repeat
                readln(n,m);
                if (n<>0) or (m<>0) then
                begin
                        for i:=1 to n do
                                read(a[i]);
                        for i:=1 to m do
                                read(b[i]);
                        check:=false;
                        s:='';
                        try(1);
                        if check=false then writeln(-1);
                end;
        until (n=0) and (m=0);
end;
begin
        assign(input,'ddd.inp');
        assign(output,'ddd.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.