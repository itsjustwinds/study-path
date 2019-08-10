const
        fi='magic.inp';
        fo='magic.out';
var
        s:int64;
        dd:array[12345678..87654321] of boolean;
        qq,t:array[1..10000000] of int64;
        i,x,first,last,tmp:longint;
        f:text;
        kq:int64;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        s:=0;
        for i:=1 to 8 do
        begin
                read(f,x);
                s:=s*10+x;
        end;
        close(f);
end;
procedure push(s:int64);
begin
        inc(last);
        qq[last]:=s;
        dd[s]:=false;
end;
function pop:int64;
begin
        pop:=qq[first];
        inc(first);
end;
function a(s:int64):int64;
var
        s1,sk:string;
        x:longint;
        kq:int64;
begin
        str(s,sk);
        s1:='';
        for i:=8 downto 1 do
                s1:=s1+sk[i];
        val(s1,kq,x);
        exit(kq);
end;
function b(s:int64):int64;
var
        s1,sk:string;
        x:longint;
        kq:int64;
begin
        str(s,sk);
        s1:='';
        s1:=s1+sk[4];s1:=s1+sk[1];s1:=s1+sk[2];s1:=s1+sk[3];
        s1:=s1+sk[6];s1:=s1+sk[7];s1:=s1+sk[8];s1:=s1+sk[5];
        val(s1,kq,x);
        exit(kq);
end;
function c(s:int64):int64;
var
        s1,sk:string;
        x:longint;
        kq:int64;
begin
        str(s,sk);
        s1:='';
        s1:=s1+sk[1];s1:=s1+sk[7];s1:=s1+sk[2];s1:=s1+sk[4];
        s1:=s1+sk[5];s1:=s1+sk[3];s1:=s1+sk[6];s1:=s1+sk[8];
        val(s1,kq,x);
        exit(kq);
end;
procedure resultt;
var
        skq:int64;
begin
        skq:=12345678;
        while tmp<>0 do
        begin
                inc(kq);
                tmp:=t[tmp];
        end;
        write(f,kq-1);
end;
procedure bfs;
var
        sa,sb,sc,su:int64;
begin
        fillchar(dd,sizeof(dd),true);
        first:=1;
        last:=0;
        push(s);
        repeat
                   su:=pop;
                   sa:=a(su);sb:=b(su);sc:=c(su);
                   if dd[sa] then
                   begin
                        push(sa);
                        t[last]:=first-1;
                        if sa=12345678 then
                        begin
                                tmp:=last;
                                resultt;
                                exit;
                        end;
                   end;
                   if dd[sb] then
                   begin
                        push(sb);
                        t[last]:=first-1;
                        if sb=12345678 then
                        begin
                                tmp:=last;
                                resultt;
                                exit;
                        end;
                   end;
                   if dd[sc] then
                   begin
                        push(sc);
                        t[last]:=first-1;
                        if sc=12345678 then
                        begin
                                tmp:=last;
                                resultt;
                                exit;
                        end;
                   end;
        until first>last;
        if dd[12345678] then write(f,0);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        if s=12345678 then write(f,0)
        else
        bfs;
        close(f);
end;
begin
        nhap;
        xuly;
end.
