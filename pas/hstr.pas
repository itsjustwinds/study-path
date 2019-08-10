var
        a,b:ansistring;
        s1,s2,s3:ansistring;
        i,j,k,h,kq:longint;
procedure nhap;
begin
        readln(h);
        readln(a);
        readln(b);
end;
function kt(s1,s2,s3:ansistring):boolean;
var     s:ansistring;
        i,j:longint;
begin
        s:=s1+s2+s3;
        kt:=true;
        for i:=1 to length(b) do
                if abs(ord(s[i])-ord(b[i]))>h then kt:=false;
        if kt=true then exit;
        s:=s1+s3+s2;
        kt:=true;
        for i:=1 to length(b) do
                if abs(ord(s[i])-ord(b[i]))>h then kt:=false;
        if kt=true then exit;
        s:=s2+s1+s3;
        kt:=true;
        for i:=1 to length(b) do
                if abs(ord(s[i])-ord(b[i]))>h then kt:=false;
        if kt=true then exit;
        s:=s2+s3+s1;
        kt:=true;
        for i:=1 to length(b) do
                if abs(ord(s[i])-ord(b[i]))>h then kt:=false;
        if kt=true then exit;
        s:=s3+s1+s2;
        kt:=true;
        for i:=1 to length(b) do
                if abs(ord(s[i])-ord(b[i]))>h then kt:=false;
        if kt=true then exit;
        s:=s3+s2+s1;
        kt:=true;
        for i:=1 to length(b) do
                if abs(ord(s[i])-ord(b[i]))>h then kt:=false;
end;
procedure xuly;
begin
        kq:=0;
        for i:=1 to length(a)-2 do
                for j:=i+1 to length(a)-1 do
                        begin
                                s1:=copy(a,1,i);
                                s2:=copy(a,i+1,j-i);
                                s3:=copy(a,j+1,length(a)-j+1);
                                if kt(s1,s2,s3) then inc(kq);
                        end;
        writeln(kq);
end;
begin
        assign(input,'hstr.inp');
        assign(output,'hstr.out');
        reset(input);
        rewrite(output);
        nhap;
        xuly;
        close(input);
        close(output);
end.
