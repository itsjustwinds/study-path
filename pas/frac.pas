const
        maxn=10000000;
{type
        hd=record
                kt:boolean;
                vt:integer;
        end; }
var
        p,q,d,c,dem,res:int64;
        t,tmp,ttmp,i,vtc:longint;
        kq:array[1..100000000] of byte;
       // dd:array[0..100000000] of hd;
        ddvt:array[1..100000000] of integer;
        ddkt:array[1..100000000] of boolean;
procedure sub3;
begin
         fillchar(ddkt,sizeof(ddkt),false);
         {for i:=1 to 100000000 do
                dd[i].kt:=false;}
                res:=0;
                dem:=0;
                p:=p mod q;
                tmp:=0;
                while dem<c do
                begin
                        inc(dem);
                        p:=p*10;
                        if (dem=c) then
                        begin
                                inc(tmp);
                                kq[tmp]:=p div q;
                                for i:=1 to tmp do
                                        res:=(res+kq[i]) mod q;
                                break;
                        end;
                        if (p=0) then
                        begin
                                for i:=1 to tmp do
                                        res:=(res+kq[i]) mod q;
                                break;
                        end;
                        if ddkt[p]=false then
                        begin
                                inc(tmp);
                                ddkt[p]:=true;
                                ddvt[p]:=tmp;
                                kq[tmp]:=p div q;
                                p:=p mod q;
                        end
                        else
                        begin
                                c:=c-d+1;
                                vtc:=ddvt[p];
                                if d<vtc then
                                begin
                                for i:=d to vtc-1 do
                                        res:=(res+kq[i])mod q;
                                c:=c-vtc+d;
                                d:=1;
                                end
                                else d:=(d-vtc+1) mod (tmp-vtc);
                                if d=0 then d:=tmp;
                                for i:=d+vtc-1 to tmp do
                                        res:=(res+kq[i]) mod q;
                                c:=c-(tmp-d-vtc+2);
                                ttmp:=0;
                                for i:=vtc to tmp do
                                        inc(ttmp,kq[i]);
                                res:=(res+(c div (tmp-vtc+1))*ttmp) mod q;
                                c:=c mod (tmp-vtc+1);
                                for i:=vtc to vtc+c-1 do
                                        res:=(res+kq[i]) mod q;
                        end;
                end;
        writeln(res);
end;
procedure nhap;
begin
        readln(t);
        while t>0 do
        begin
                dec(t);
                readln(p,q,d,c);
                if (p<=5000000) and (q<=5000000)  then
                sub3
                else
                begin
                        p:=p mod q;
                        dem:=0;
                        res:=0;
                        while p<>0 do
                        begin
                                p:=p*10;
                                inc(dem);
                                if dem>=d then
                                        res:=(res+p div q) mod q;
                                if dem=c then break;
                                p:=p mod q;
                        end;
                        writeln(res);
                end;
        end;
end;
begin
        assign(input,'frac.inp');
        assign(output,'frac.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.
