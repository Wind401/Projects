class ContactsController < ApplicationController
    def index 
		@contacts = Contact.all 
	end
	
	def new 
		@contact = Contact.new 
	end
	
	def create
		 @contact = Contact.new(contact_params) 
  		if @contact.save 
  			flash[:success] =  "Thank you for your message! We will get back to you as soon as we can."
    		redirect_to '/contact_us' 
	  	else 
    		render 'new' 
 		end 
	end
	
	def destroy
        @contact = Contact.find(params[:id])
        if @contact.destroy
        	flash[:success] =  "Message has been deleted."
            redirect_to '/contacts'
        end
        # respond_to do |format|
        #   format.html { redirect_to '/show' }
        #   format.json { head :no_content }
        # end
    end
    
	
  private
  	def contact_params
      params.require(:contact).permit(:first_name, :last_name, :subject, :email, :message)
    end
    
end
