class Post < ActiveRecord::Base
  belongs_to :user
  
 def self.search(search)
   if search
    
    
     self.where("Content || Title  LIKE ?", "%#{search}%")
  # self.where("user_id like ? , %#{search}%")
  else
    self.all
  end
 end
  #  if search
      #find(:all, :conditions => ['Title LIKE ?', "%#{search}%"])
      
   # else
    #  find(:all)
    #end
  #end
#   searchable do
#     text :title, :content
#   end
end

